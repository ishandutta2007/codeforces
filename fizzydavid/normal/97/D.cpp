#include<bits/stdc++.h>
using namespace std;
int n,m,k,ex,ey;
char g[155][155];
bitset<22555>mm,a,b;
string s;
int pos(int x,int y){return (x-1)*m+y-1;}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        cin>>g[i][j];
        if(g[i][j]=='#')b.set(pos(i,j));
        else
        {
            a.set(pos(i,j)),mm.set(pos(i,j));
            if(g[i][j]=='E')ex=i,ey=j;
        }
    }
    if(a.count()==1){cout<<0<<endl;return 0;}
    cin>>s;
    for(int i=0;i<k;i++)
    {
        if(s[i]=='D')a=(a<<m)&mm|((b>>m)&a);
        else if(s[i]=='U')a=(a>>m)&mm|((b<<m)&a);
        else if(s[i]=='R')a=(a<<1)&mm|((b>>1)&a);
        else a=(a>>1)&mm|((b<<1)&a);
        if(a.count()==1&&a[pos(ex,ey)]==1)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}