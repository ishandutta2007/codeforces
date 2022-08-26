#include<bits/stdc++.h>
#define maxn 324003
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll p,q,r,t,n;
ll gcd(ll x,ll y){
    if (x==x/y*y) return y;
    else return gcd(y,x-x/y*y);
}

int main()
{
    cin >> n;
    while (n--){
        scanf("%lld%lld%lld",&p,&q,&r);
        if (p==0) {
            printf("Finite\n");
            continue;
        }
        t=gcd(p,q);
        q/=t;
        while (true){
            t=gcd(q,r);
            if (t==1) break;
            while (q/t*t==q) q/=t;
        }
        if (q>1) printf("Infinite\n"); else printf("Finite\n");
    }
    return 0;
}