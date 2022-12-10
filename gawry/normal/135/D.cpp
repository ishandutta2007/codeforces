#include<set>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> p2;
int n,m,ans,nr[1010][1010],next_nr;
char t[1010][1010];
bool b[1010][1010];
vector<p2> cur;
map<p2,vector<p2> > cur_e;
void add(int x,int y){
  if(x<0||y<0||x>=n||y>=m||t[x][y]!='1'||nr[x][y]==next_nr)return;
  cur.push_back(p2(x,y));
  nr[x][y]=next_nr;
}
void add(int x,int y,int x2,int y2){
  if(x<0||y<0||x>=n||y>=m||t[x][y]!='1')return;
  if(x2<0||y2<0||x2>=n||y2>=m||t[x2][y2]!='1')return;
  cur_e[p2(x,y)].push_back(p2(x2,y2));
  cur_e[p2(x2,y2)].push_back(p2(x,y));
}
bool outside;
void dfs(int x,int y){
  outside|=x<0||y<0||x>=n||y>=m;
  if(x<0||y<0||x>=n||y>=m||t[x][y]!='0'||b[x][y])return;
  b[x][y]=true;
  dfs(x-1,y);
  dfs(x+1,y);
  dfs(x,y-1);
  dfs(x,y+1);
  dfs(x-1,y-1);
  dfs(x-1,y+1);
  dfs(x+1,y-1);
  dfs(x+1,y+1);
  int dx[8]={-1,-1,-1,0,1,1,1,0},dy[8]={-1,0,1,1,1,0,-1,-1};
  for(int i=0;i<8;i++)add(x+dx[i],y+dy[i]);
}
bool a[1010][1010];
void mark(int x,int y){
  if(x<0||y<0||x>=n||y>=m||nr[x][y]!=next_nr-1)return;
  nr[x][y]=next_nr;
  mark(x-1,y);
  mark(x+1,y);
  mark(x,y-1);
  mark(x,y+1);
}
main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)scanf(" %s",t[i]);
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(t[i][j]=='0'&&!b[i][j]){
    cur.clear();
    cur_e.clear();
    ++next_nr;
    outside=false;
    dfs(i,j);
    if(outside)continue;
    if(cur.empty())continue;
    ++next_nr;
    mark(cur[0].first,cur[0].second);
    bool ok=true;
    set<p2> seen(cur.begin(),cur.end());
    for(int i=0;i<cur.size();i++){
      ok&=nr[cur[i].first][cur[i].second]==next_nr;
      int cnt=0;
      cnt+=seen.count(p2(cur[i].first,cur[i].second-1));
      cnt+=seen.count(p2(cur[i].first,cur[i].second+1));
      cnt+=seen.count(p2(cur[i].first-1,cur[i].second));
      cnt+=seen.count(p2(cur[i].first+1,cur[i].second));
      ok&=cnt==2;
    }
    //printf("%d,%d %d\n",i,j,cur.size());
    if(!ok)continue;
    ans=max(ans,(int)cur.size());
  }
  for(int i=1;i<n;i++)for(int j=1;j<m;j++)if(t[i][j]=='1'&&t[i-1][j]=='1'&&t[i][j-1]=='1'&&t[i-1][j-1]=='1')ans=max(ans,4);
  printf("%d\n",ans);
}