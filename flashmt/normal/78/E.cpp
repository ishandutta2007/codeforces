#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
#define fr(a,b,c) for(a=b;a<=c;a++)
using namespace std;
const int dx[]={-1,0,1,0}; 
      int dy[]={0,1,0,-1};
char a[11][11],b[11][11];
int n,t,fx,fy,d[11][11][11][11],u=0,v=0,c[1111][1111],cc[1111];
int aa[1111],bb[1111],dd[1111],tmp,ux[1111],uy[1111],vx[1111],vy[1111];
vector < pair<int,int> > q;

void bfs(int z,int sx,int sy)
{
    pair <int,int> u;
    int i=0,j;
    q.clear();
    q.push_back(make_pair(sx,sy));
    d[sx][sy][sx][sy]=0;
    while (i<=q.size()-1) 
    {
       u=q[i++];
       fr(j,0,3)
       {
          int x=u.first+dx[j],y=u.second+dy[j];
          if (x>=0 && y>=0 && x<n && y<n && d[sx][sy][x][y]<0 && a[x][y]!='Y')
          {
             d[sx][sy][x][y]=d[sx][sy][u.first][u.second]+1;
             if (z && d[sx][sy][x][y]>d[fx][fy][x][y] && d[fx][fy][x][y]>=0) 
             {
                 d[sx][sy][x][y]=-1; continue;    
             }
             if (z && d[sx][sy][x][y]==d[fx][fy][x][y] && d[fx][fy][x][y]>=0) 
             {
                 if (b[x][y]<='0' || b[x][y]>'9') d[sx][sy][x][y]=-1; 
                 continue;    
             }
             q.push_back(make_pair(x,y));      
          }      
       }   
    }    
}

int dfs(int x)
{
    int i,ii;
    fr(ii,1,cc[x])
    {
      i=c[x][ii];
      if (!dd[i])
      {
         tmp=i; dd[i]=x;
         if (!bb[i] || dfs(bb[i])) return 1;         
      }
    }
    return 0;
}

int find()
{
    int i;
    memset(dd,0,sizeof(dd));
    fr(i,1,u)
      if (!aa[i])
        if (dfs(i)) return 1;
    return 0;   
}

void inc()
{
    int x,y;
    while (tmp)
    {
       x=dd[tmp]; y=tmp; tmp=aa[x];
       aa[x]=y; bb[y]=x;   
    } 
}

int main()
{
    int i,j,k;
    cin >> n >> t;
    fr(i,0,n-1) cin >> a[i];
    fr(i,0,n-1) cin >> b[i];
    memset(d,-1,sizeof(d));
    fr(i,0,n-1)
     fr(j,0,n-1)
       if (a[i][j]=='Z') bfs(0,i,j),fx=i,fy=j;
    fr(i,0,n-1)
     fr(j,0,n-1)
       if (a[i][j]!='Z' && a[i][j]!='Y') bfs(1,i,j);
    fr(i,0,n-1)
     fr(j,0,n-1)
     {
        if (a[i][j]>'0' && a[i][j]<='9') 
        {
           int x=int(a[i][j])-48;             
           fr(k,1,x)
           {
              u++; ux[u]=i; uy[u]=j;      
           }
        } 
        if (b[i][j]>'0' && b[i][j]<='9') 
        {
           int x=int(b[i][j])-48;
           fr(k,1,x)
           {
              v++; vx[v]=i; vy[v]=j;      
           }
        }       
     } 
    fr(i,1,u)
      fr(j,1,v)
       if (d[ux[i]][uy[i]][vx[j]][vy[j]]>=0 && d[ux[i]][uy[i]][vx[j]][vy[j]]<=t) 
         c[i][++cc[i]]=j;
    while (find()) inc();
    int re=0;
    fr(i,1,u)
      if (aa[i]) re++;
    cout << re << endl;
    return 0;
}