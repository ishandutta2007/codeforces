#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;
typedef ll ll;
ll mul(ll a,ll b,ll p)
{
    ll ans=(long double)a*b/p;
    return (a*b-ans*p+p)%p;
}
ll exgcd(ll a,ll b,ll &x,ll &y) //ax+by=r
{
    if(b==0) return (x=1,y=0,a);
    if(a==0) return (x=0,y=1,b);
    ll r=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
ll ni(ll a,ll b) //x*a%b=1
{
    ll x,y;
    if (exgcd(a,b,x,y) != 1) return -1;
    (((x%=b)+=b))%=b;
    return x;
}
pair<ll, ll> crt(vector<ll> A, vector<ll> B,vector<ll>M){
    ll x = 0, m = 1;
    for(int i = 0; i < A.size() ; ++i){
        ll a = A[i] * m, b = B[i] - A[i] * x, d = __gcd(M[i],a);
        if(b % d != 0) return make_pair(0,-1); // 
        ll t = mul(b / d , ni(a / d, M[i] / d) , ( M[i] / d ));
        x = x + m * t;
        m *= M[i] / d;
    }
    m = abs(m);
    return make_pair(x % m, m);
}
int main(){
    int n, m, x, y, vx, vy;
    scanf("%d %d %d %d %d %d", &n,&m,&x,&y,&vx,&vy);
    auto u = crt(vector<long long>{1ll * vx, 1ll * vy}, vector<long long>{1ll * -x, 1ll*  -y}, vector<long long>{1ll *n, 1ll * m});
    if (u.second == -1) puts("-1");
    else {
        int xx = 0, yy = 0;
        if (u.first <= 0) u.first += u.second;
        if (vx) {
            if (vx < 0) {
                if (((u.first - x) / n) & 1)
                    xx = n;
                else
                    xx = 0;
            } else {
                if (((u.first - (n - x)) / n) & 1)
                    xx = 0;
                else
                    xx = n;
            }
        } else {
            xx = x;
        }


        if (vy) {
            if (vy < 0) {
                if (((u.first - y) / m) & 1)
                    yy = m;
                else
                    yy = 0;
            } else {
                if (((u.first - (m - y)) / m) & 1)
                    yy = 0;
                else
                    yy = m;
            }
        } else {
            yy = y;
        }
        printf("%d %d\n", xx, yy);
    }
    return 0;
}