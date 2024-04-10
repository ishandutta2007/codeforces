#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll query,n,p,q,s,t,a,b,u;

ll gcd(ll x,ll y)
{
    if (x%y==0) return y; else return gcd(y,x%y);
}

int main()
{
    scanf("%lld",&query);
    while (query--)
    {
        scanf("%lld%lld%lld%lld",&p,&q,&a,&b); b-=a; q-=p;
        if (a==0){if (p==0) cout << 0 << endl; else cout << -1 << endl;}
        else if (b==0) {if (q==0) cout << 0 << endl; else cout << -1 << endl;}
        else {
            s=a/gcd(a,b); t=b/gcd(a,b);
            u=max((p-1)/s+1,(q-1)/t+1);
            cout << u*(s+t)-p-q << endl;
        }
    }
    return 0;
}