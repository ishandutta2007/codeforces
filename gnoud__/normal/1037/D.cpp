#include <bits/stdc++.h>
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define read2(a,b) read(a),read(b)
#define pb push_back
using namespace std;
const int N=200010;
int dd[N],a[N],n,ok=1,b[N];
vector<int> ke[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
queue<int> q;
void BFS(int u)
{
    q.push(u);int o=0;
    dd[1]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();o++;
        if(b[o]!=u) {cout<<"No";ok=0;return;}
        forv(v,ke[u]) if(!dd[v])
        {
            dd[v]=1;
            q.push(v);
        }
    }
}
bool cmp(int u,int v) {return a[u]<a[v];}
int main()
{
    //freopen("1037D.inp","r",stdin);
    read(n);
    forinc(i,1,n-1)
    {
        int u,v;
        read2(u,v);
        ke[u].pb(v);
        ke[v].pb(u);
    }
    forinc(i,1,n) {int x;read(x);a[x]=i;b[i]=x;}
    forinc(i,1,n) sort(ke[i].begin(),ke[i].end(),cmp);
    BFS(1);
    if(ok) cout<<"Yes";
}