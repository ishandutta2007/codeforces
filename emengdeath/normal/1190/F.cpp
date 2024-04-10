#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
long long m, p;
int n, g;
typedef long long ll;
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
vector<ll> s, fac,s_cnt;
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
        s.push_back(N);
        return;
    }
    q=pollard_rho(N);
    div(q);div(N/q);
}
long long gcd(long long x ,long long y) {
    return !y ? x : gcd(y, x % y);
}
void dfs(int x, int y, ll z){
    if (x > y) {
        fac.push_back(z);
        return;
    }
    for (int i = 0; i <= s_cnt[x]; i ++) {
        dfs(x + 1, y, z);
        z *= s[x];
    }
}
bool dfs_check(int i, int k, ll x, ll p, ll t) {
    if (i > k) return 1;
    ll mask = (1ll << i) - 1;
    if ((t & mask) == (x & mask) && dfs_check(i + 1, k, x, p * p, t)) return 1;
    if (((t * p) & mask) == (x & mask) && dfs_check(i + 1, k, x, p * p, t * p)) return 1;
    return 0;
}
int main()
{
    srand(19260817);
    scanf("%d %lld %lld", &n, &m, &p);
    div(m);
    ll fim = m;
    s.erase(unique(s.begin(), s.end()), s.end());
    for (auto u:s)
        fim = fim / u * (u - 1);

    if (gcd(p, m) != 1) {
        if (fim - 1 < n) {
            printf("-1");
            return 0;
        }
        int l = 2;
        while (n --) {
            while (gcd(m, l) != 1) l ++;
            printf("%d ", l);
            ++l;
        }
        return 0;
    }
    s.clear();
    div(m);
    if (s[0] == 2 && s.size() > 2) {
        vector<ll> ans;
        for (int i = 3; i < m && ans.size() < n; i += 2)
            if (!dfs_check(3, s.size(), i, p, 1)) ans.push_back(i);
        if (ans.size() < n ){
            printf("-1");
            return 0;
        }
        for (auto u:ans)
            printf("%lld ", u);
        return 0;
    }
    s.clear();
    div(fim);
    sort(s.begin(), s.end());
    int tot = 0;
    s_cnt.push_back(0);
    for (int i = 0; i < s.size(); i ++)
        if (s[i] != s[tot]) s[++tot] = s[i], s_cnt.push_back(1);
        else
            s_cnt[tot] ++;
    tot = min(tot, (int)s.size() - 1);
    dfs(0, tot, 1);
    g = 0;
    while (++g){
        bool sig = (gcd(g, m) == 1);
        for (int i = 0; i <= tot;  i++)
            sig &= (qp(g, fim / s[i], m) > 1);
        if (sig) break;
    }
    sort(fac.begin(), fac.end());
    ll len = 0;
    while (qp(p, fac[len], m) != 1) len ++;

    len = fac[len];
    if (len == fim) {
        printf("-1");
        return 0;
    }
    int l = 0;
    vector<ll> ans;
    for (int l = 0; l < fim && ans.size() < n; l ++)
        if (l % (fim / len) != 0) {
            ans.push_back(qp(g,l,m));
        }
    if (ans.size() < n ){
        printf("-1");
        return 0;
    }
    for (auto u:ans)
        printf("%lld ", u);
    return 0;
}