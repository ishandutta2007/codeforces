#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,m,k,i,j,a[1003][1003]={0},visi[1003][1003]={0},cnt,V,d[1003][1003]={0};
struct s
{
    long value,x,y;
};
bool cmp(s lhs , s rhs)
{
    return lhs.value<rhs.value;
}
vector < s > b;
s p[1003][1003];
s fp(long xx,long yy)
{
    if(p[xx][yy].x==xx && p[xx][yy].y==yy)return p[xx][yy];
    else return p[xx][yy]=fp(p[xx][yy].x,p[xx][yy].y);
}
void merge(long x1,long y1,long x2,long y2)
{
    if(a[x1][y1]>a[x2][y2]) return ;
    s p1=fp(x1,y1),p2=fp(x2,y2);
    p[p2.x][p2.y].value+=p1.value;
    p[p1.x][p1.y]=p2;
}
void dfs(long i , long j)
{
    if(visi[i][j]) return ;
    visi[i][j]=1;
    if(a[i][j]<V || cnt==0) {a[i][j]=0;return ;}
    d[i][j]=V;
    cnt--;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
int main()
{
    io
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    {
        cin>>a[i][j];
        p[i][j]={1,i,j};
        b.pb({a[i][j],i,j});
    }
    s t,pp;
    sort(b.begin(),b.end(),cmp);
    reverse(b.begin(),b.end());
    for(i=0;i<n*m;++i)
    {
        merge(b[i].x,b[i].y,b[i].x-1,b[i].y);
        merge(b[i].x,b[i].y,b[i].x+1,b[i].y);
        merge(b[i].x,b[i].y,b[i].x,b[i].y-1);
        merge(b[i].x,b[i].y,b[i].x,b[i].y+1);
        pp=fp(b[i].x,b[i].y);
        if(!(k%b[i].value))
        if(k/b[i].value<=pp.value) {cnt=k/b[i].value,V=b[i].value;break;}
    }
    if(i==n*m) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    dfs(b[i].x,b[i].y);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;j++)
        cout<<d[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}