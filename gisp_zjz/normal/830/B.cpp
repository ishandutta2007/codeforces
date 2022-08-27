#include<bits/stdc++.h>
#define maxn 500000

using namespace std;
typedef long long ll;

ll ans,k,o,n,m,b[maxn],pos,s[maxn];
vector <ll> h[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void add_(ll x,ll y)
{
    while (x<maxn) s[x]+=y,x+=lowbit(x);
}

ll qry(ll x)
{
    ll rt=0; while (x) rt+=s[x],x-=lowbit(x); return rt;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) h[b[i]].push_back(i);
    for (int i=0;i<n;i++) add_(i+1,1); pos=0;
    for (int i=1;i<=100000;i++) {
        if (!h[i].size()) continue;
        k=0;
        for (int j=1;j<h[i].size();j++)
            if ((h[i][j]+n-pos)%n>(h[i][k]+n-pos)%n) k=j;
        o=h[i][k];
        if (o>=pos) ans+=qry(o+1)-qry(pos+1);
        else ans+=qry(n)-qry(pos+1)+qry(o+1);
        for (int j=0;j<h[i].size();j++) add_(h[i][j]+1,-1);
        pos=o;
    }
    cout << ans+1 << endl;
}