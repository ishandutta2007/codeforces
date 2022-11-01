#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
const int N=2510,base=1e9+7;
int n,m,q,id;
ull s[N][N],pw[100010];
map<int,map<int,int> > f[N][N];
void update(int a,int b,ull x)
{
    for(int i=a;i<=n;i+=i&-i)
    for(int j=b;j<=m;j+=j&-j) s[i][j]+=x;
}
ull get(int a,int b)
{
    ull g=0;
    for(int i=a;i;i-=i&-i)
    for(int j=b;j;j-=j&-j) g+=s[i][j];
    return g;
}
void Update(int a,int b,int c,int d,ull x)
{
    update(a,b,x);
    update(a,d+1,-x);
    update(c+1,b,-x);
    update(c+1,d+1,x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("869.inp","r",stdin);
    cin>>n>>m>>q;
    pw[0]=1;
    forinc(i,1,q) pw[i]=pw[i-1]*base;
    while(q--)
    {
        int t,x,y,u,v;
        cin>>t>>x>>y>>u>>v;
        if(t==1)
        {
            f[x][y][u][v]=++id;
            Update(x,y,u,v,pw[id]);
        }
        else if(t==2) Update(x,y,u,v,-pw[f[x][y][u][v]]);
        else if(t==3)
        {
            if(get(x,y)==get(u,v)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}