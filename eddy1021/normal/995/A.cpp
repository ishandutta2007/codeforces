#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n, k, a[5][N];
vector<tuple<int,int,int>> ans;
bool done(){
  return accumulate(a[2], a[2]+n+1, 0)+
         accumulate(a[3], a[3]+n+1, 0)==0;
}
int to[]={0,0,1,4};
void push_in(){
  for(int i=2; i<=3; i++)
    for(int j=1; j<=n; j++)
      if(a[i][j] and a[i][j]==a[to[i]][j]){
        ans.push_back(make_tuple(a[i][j], to[i], j));
        a[i][j]=a[to[i]][j]=0;
      }
}
vector<pair<int,int>> pos;
bool move(){
  int si=-1, sj=-1;
  for(int i=2; i<=3; i++)
    for(int j=1; j<=n; j++)
      if(a[i][j] == 0)
        si=i, sj=j;
  if(si == -1) return false;
  size_t at=0;
  while(pos[at] != make_pair(si, sj)) at++;
  for(size_t i=1; i<pos.size(); i++){
    int curi, curj;
    tie(curi, curj)=pos[(at+i)%pos.size()];
    int toi, toj;
    tie(toi, toj)=pos[(at+i-1)%pos.size()];
    if(a[curi][curj]){
      ans.push_back(make_tuple(a[curi][curj], toi, toj));
      a[toi][toj]=a[curi][curj];
      a[curi][curj]=0;
    }
  }
  return true;
}
int main(){
  cin>>n>>k;
  for(int i=1; i<=4; i++)
    for(int j=1; j<=n; j++)
      cin>>a[i][j];
  for(int i=1; i<=n; i++)
    pos.push_back({2,i});
  for(int i=n; i>=1; i--)
    pos.push_back({3,i});
  while(not done()){
    push_in();
    if(not move()){
      puts("-1");
      exit(0);
    }
  }
  printf("%d\n", (int)ans.size());
  for(auto i: ans)
    printf("%d %d %d\n",
           get<0>(i),
           get<1>(i),
           get<2>(i));
}