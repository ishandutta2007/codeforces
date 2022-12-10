#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,d[60][60];
char s[60][60];
main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)scanf(" %s",&s[i]);
  int r=10000;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    typedef pair<int,int> p2;
    vector<p2> q[2];
    for(int x=0;x<n;x++)for(int y=0;y<m;y++)d[x][y]=10000;
    d[i][j]=0;
    q[0].push_back(p2(i,j)); 
    while(!q[0].empty()){
      for(int k=0;k<q[0].size();k++){
        int x=q[0][k].first,y=q[0][k].second;
        if(x&&d[x-1][y]>d[x][y]+(s[x][y]!=s[x-1][y]))d[x-1][y]=d[x][y]+(s[x][y]!=s[x-1][y]),q[s[x][y]!=s[x-1][y]].push_back(p2(x-1,y));
        if(y&&d[x][y-1]>d[x][y]+(s[x][y]!=s[x][y-1]))d[x][y-1]=d[x][y]+(s[x][y]!=s[x][y-1]),q[s[x][y]!=s[x][y-1]].push_back(p2(x,y-1));
        if(x+1<n&&d[x+1][y]>d[x][y]+(s[x][y]!=s[x+1][y]))d[x+1][y]=d[x][y]+(s[x][y]!=s[x+1][y]),q[s[x][y]!=s[x+1][y]].push_back(p2(x+1,y));
        if(y+1<m&&d[x][y+1]>d[x][y]+(s[x][y]!=s[x][y+1]))d[x][y+1]=d[x][y]+(s[x][y]!=s[x][y+1]),q[s[x][y]!=s[x][y+1]].push_back(p2(x,y+1));
      }
      q[0]=q[1];
      q[1].clear();
    }
    int worst=0;
    for(int x=0;x<n;x++)for(int y=0;y<m;y++)worst=max(worst,d[x][y]);
    worst+=worst%2!=(s[i][j]=='B');
//    printf("%d %d : %d\n",i,j,worst);
    r=min(r,worst);
  }
  printf("%d\n",r);
}