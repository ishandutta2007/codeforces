#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <set>
#include <random>
#include <chrono>
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1000000;
long long a[N];
int n;
set<long long>s, s1;
long long ans;
int rndNum(int n){
    return rnd() % n;
}
void update(long long x) {
    if (s.find(x) != s.end()) {
        return;
    }
    s.insert(x);
    long long tmp = 0;
    for (int i = 1; i <= n && tmp < ans; i ++)
        if (a[i] < x) {
            tmp += x - a[i];
        } else
        tmp += min(a[i] - a[i] / x * x, a[i] /x * x + x - a[i]);
    ans = min(1ll * ans, tmp);
}
typedef long long ll;
/*long long mul(long long x,long long y,long long n)
{
long long ret=0,tmp=x%n;
while(y)
{
if(y&0x1)if((ret+=tmp)>n)ret-=n;
if((tmp<<=1)>n)tmp-=n;
y>>=1;
}
return ret;
}*/
ll mul(ll a,ll b,ll p)
{
    ll ans=(long double)a*b/p;
    return (a*b-ans*p+p)%p;
}
ll add(ll a,ll b,ll p)
{
    a+=b;
    return a%p;
}
ll qp(ll a,ll n,ll p)
{
    ll ans=1;
    while(n)
    {
        if(n&1ll) ans=mul(ans,a,p);
        a=mul(a,a,p);
        n>>=1;
    }
    return ans;
}
ll pri[12]{2,3,5,7,11,13,17,19,23,29,31,37};
struct is_prime{
    bool flag;
    bool check(ll a,ll p)
    {
        ll now=p-1;
        if(qp(a,now,p)!=1) return false;
        while(now%2==0)
        {
            now>>=1;
            ll ans=qp(a,now,p);
            if(ans==p-1) return true;
            if(ans!=1) return false;
        }
        return true;
    }
    is_prime(ll p)
    {
        flag=(p==2||p%2);
        for(int i=0;i<12&&flag&&pri[i]<p;++i)
            flag&=check(pri[i],p);
    }
};
ll pollard_rho(ll n)
{
    ll a,b,c,del;
    while(true) {
        c = rand() % n;
        a = b = rand() % n;
        b = (mul(b, b, n) + c) % n;
        while(a != b) {
            del = a-b;
            del = __gcd(abs(del), n);
            if(del > 1 && del < n) {
                return del;
            }
            a = (mul(a, a, n) + c) % n;
            b = (mul(b, b, n) + c) % n;
            b = (mul(b, b, n) + c) % n;
        }
    }
}
void div(ll N)
{
    if(N==1) return;
    ll q;
    if(is_prime(N).flag)
    {
        update(N);
        return;
    }
    q=pollard_rho(N);
    div(q);div(N/q / __gcd(q, N/q));
}
void get(long long x) {
    if (x <= 0) return;
    div(x);
}
const int S = 50;
int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    ans = n;
    int st = 1;
    for (int i = 1; i <= 250; i ++) {
        if (i % 20 == 1)
            random_shuffle(a + i, a + n + 1, rndNum);
        while (st <= n && s1.find(st) != s1.end()) st ++;
        if (st > n) break;
        s1.insert(st);
        for (int j = -S; j <= S ; j ++) {
            get(a[st] + j);
        }
    }
    printf("%d\n", ans);
    return 0;
}