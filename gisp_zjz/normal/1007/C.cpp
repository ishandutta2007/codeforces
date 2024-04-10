#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef long long ll;
ll n;

int query(ll x,ll y){
    printf("%I64d %I64d\n",x,y);
    fflush(stdout);
    int w; scanf("%d",&w);
    return w;
}

void solve2(ll a,ll p,ll b,ll c,ll q,ll d);
void solve(ll a,ll b,ll c,ll d){
    ll p,q,o;
    if (b-a<4&&d-c<4){
        for (ll i=a;i<=b;i++) for (ll j=c;j<=d;j++) {
            o=query(i,j);
            if (!o) return;
        }
    }
    p=(a*6+b)/7;
    q=(c*6+d)/7;
    o=query(p,q);
    if (!o) return;
    if (o==1) solve(p+1,b,c,d);
    else if (o==2) solve(a,b,q+1,d);
    else solve2(a,p-1,b,c,q-1,d);
}

void solve2(ll a,ll p,ll b,ll c,ll q,ll d){
    ll mx,my,o;
    if (a>p) solve(a,b,c,q); else if (c>q) solve(a,p,c,d);
    else {
        mx=(a+p*3)/4; my=(c+q*3)/4;
        o=query(mx,my);
        if (!o) return;
        if (o==1) solve2(mx+1,p,b,c,q,d);
        else if (o==2) solve2(a,p,b,my+1,q,d);
        else solve2(a,mx-1,b,c,my-1,d);
    }
}

int main(){
    cin >> n;
    solve(1,n,1,n);
    return 0;
}