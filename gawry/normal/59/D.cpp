#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int MAX=100123;
int n,permutation[3*MAX],team[MAX][4],k,team_nr[3*MAX];
bool taken[3*MAX];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=3*n;i++){
    scanf("%d",&permutation[i]);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++){
      scanf("%d",&team[i][j]);
      team_nr[team[i][j]]=i;
    }
  }
  scanf("%d",&k);
  for(int i=1;i<=3*n;i++){
    int x=permutation[i];
    if(taken[x]){
      continue;
    }
    int t=team_nr[x];
    bool found=false;
    for(int j=1;j<=3;j++){
      taken[team[t][j]]=true;
      found|=team[t][j]==k;
    }
    //printf("x=%d found=%d\n",x,found);
    if(!found)continue;
    if(x==k){
      int y=-1,z=-1;
      for(int j=1;j<=3;j++)if(team[t][j]!=x){
        if(y==-1)y=team[t][j];else z=team[t][j];
      }
      if(y>z)swap(y,z);
      vector<int> p,q;
      for(int a=1;a<=3*n;a++)if(taken[a]){
        if(team_nr[a]!=t){
          p.push_back(a);
        }
      }else{
        q.push_back(a);
      }
      sort(p.begin(),p.end());
      sort(q.begin(),q.end());
      q.insert(q.begin(),z);
      q.insert(q.begin(),y);
      int a=0,b=0;
      while(a<p.size()&&b<q.size()){
        if(p[a]<q[b]){
          printf("%d ",p[a++]);
        }else{
          printf("%d ",q[b++]);
        }
      }
      while(a<p.size()){
        printf("%d ",p[a++]);
      }
      while(b<q.size()){
        printf("%d ",q[b++]);
      }
      printf("\n");
      return 0;
    }
    for(int i=1;i<=3*n;i++)if(i!=k){
      printf("%d ",i);
    }
    printf("\n");
    return 0;
  }
  return 0;
}