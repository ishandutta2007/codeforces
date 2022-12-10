#include<cstdio>
#include<vector>
using namespace std;
vector<int> e[101];
#define INF 1000000000
int n,m,a,b,k,s[101],t[101],r[101],d[101][101],seen[101],next_seen;
bool must[101][101];
main(){
  scanf("%d %d %d %d",&n,&m,&a,&b);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=i==j?0:INF;
  while(m--){
    int x,y;
    scanf("%d %d",&x,&y);
    e[x].push_back(y);
    d[x][y]=1;
  }
  for(int z=1;z<=n;z++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][z]+d[z][j]);
  scanf("%d",&k);
  for(int i=0;i<k;i++)scanf("%d %d",&s[i],&t[i]);
  for(int i=0;i<k;i++)for(int j=1;j<=n;j++){
    must[i][j]=d[s[i]][j]+d[j][t[i]]==d[s[i]][t[i]];
    for(int z=1;z<=n;z++)must[i][j]&=z==j||d[s[i]][z]!=d[s[i]][j]||d[z][t[i]]!=d[j][t[i]]||d[s[i]][z]+d[z][t[i]]!=d[s[i]][t[i]];
//    if(must[i][j])printf("%d %d\n",i,j);
  }
  for(int i=1;i<=n;i++)r[i]=INF;
  r[b]=0;
  int phase=0;
  while(++phase){
    bool found=false;
    for(int i=0;i<k;i++)if(d[s[i]][t[i]]<INF)for(int j=1;j<=n;j++)if(must[i][j]&&r[j]==INF){
      // must all shortest paths from j to t[i] hit some processed vertex?
      vector<int> q(1,j);
      seen[j]=++next_seen;
      for(int z=0;z<q.size();z++){
        int cur=q[z];
        for(int next=1;next<=n;next++)if(d[cur][next]==1&&seen[next]!=next_seen&&d[cur][t[i]]==1+d[next][t[i]]&&r[next]>=phase){
          q.push_back(next);
          seen[next]=next_seen;
        }
      }
      if(seen[t[i]]!=next_seen){
        r[j]=phase;
        found=true;
      }
    }
    if(!found)break;
  }
  printf("%d\n",r[a]==INF?-1:r[a]);
}