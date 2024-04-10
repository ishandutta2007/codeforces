#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int r,c,d[1010][1010];
char t[1010][1010];
main(){
  scanf("%d %d",&r,&c);
  for(int i=0;i<r;i++)scanf(" %s",t[i]);
  memset(d,60,sizeof(d));
//  printf("%d\n",d[0][0]);
  typedef pair<int,int> p2;
  vector<p2> q;
  for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(t[i][j]=='E')q.push_back(p2(i,j)),d[i][j]=0;
  for(int i=0;i<q.size();i++){
    int x=q[i].first,y=q[i].second;
    if(x&&t[x-1][y]!='T'&&d[x-1][y]>d[x][y]+1){
      q.push_back(p2(x-1,y));
      d[x-1][y]=d[x][y]+1;
    }
    if(y&&t[x][y-1]!='T'&&d[x][y-1]>d[x][y]+1){
      q.push_back(p2(x,y-1));
      d[x][y-1]=d[x][y]+1;
    }
    if(x+1<r&&t[x+1][y]!='T'&&d[x+1][y]>d[x][y]+1){
      q.push_back(p2(x+1,y));
      d[x+1][y]=d[x][y]+1;
    }
    if(y+1<c&&t[x][y+1]!='T'&&d[x][y+1]>d[x][y]+1){
      q.push_back(p2(x,y+1));
      d[x][y+1]=d[x][y]+1;
    }
  }
  int my=-1;
  for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(t[i][j]=='S')my=d[i][j];
  int ans=0;
  for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(t[i][j]>='0'&&t[i][j]<='9'&&d[i][j]<=my)ans+=t[i][j]-'0';
  printf("%d\n",ans);
}