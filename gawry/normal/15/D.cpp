#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<list>
#include<iostream>
using namespace std;
void window_min(int *input,int *output,int len,int window){
  list<int> pos;
  for(int i=0;i<len;i++){
    while(!pos.empty()&&input[pos.back()]>input[i])pos.pop_back();
    pos.push_back(i);
    while(pos.front()+window<=i)pos.pop_front();
    if(i>=window-1)output[i-window+1]=input[pos.front()];
  }
}
int n,m,a,b,t[1010][1010],z[1010][1010];
typedef long long int64;
int64 s[1010][1010];
bool dead[1010][1010];
void kill(int x,int y){
  for(int i=max(x-a+1,0);i<min(x+a,n);i++)for(int j=max(y-b+1,0);j<min(y+b,m);j++)dead[i][j]=1;
}
main(){
  scanf("%d %d %d %d",&n,&m,&a,&b);
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&t[i][j]);
  for(int i=0;i<n;i++)for(int j=m-1;j>=0;j--)s[i][j]=s[i][j+1]+t[i][j];
  for(int i=n-1;i>=0;i--)for(int j=0;j<m;j++)s[i][j]+=s[i+1][j];
  for(int i=0;i<n;i++){
    window_min(t[i],z[i],m,b);
  }
  for(int i=0;i<m;i++){
    int input[1010]={},output[1010]={};
    for(int j=0;j<n;j++)input[j]=z[j][i];
    window_min(input,output,n,a);
    for(int j=0;j<n;j++)z[j][i]=output[j];
  }
  typedef pair<int,int> p2;
  typedef pair<int64,p2> p3;
  vector<p3> c,r;
  for(int i=0;i+a<=n;i++)for(int j=0;j+b<=m;j++){
    c.push_back(p3(s[i][j]-s[i+a][j]-s[i][j+b]+s[i+a][j+b]-(int64)z[i][j]*a*b,p2(i,j)));
//    cout<<c.back().first<<" "<<c.back().second.first<<" "<<c.back().second.second<<endl;
  }
  sort(c.begin(),c.end());
  for(int i=0;i<c.size();i++)if(!dead[c[i].second.first][c[i].second.second]){
    r.push_back(c[i]);
    kill(c[i].second.first,c[i].second.second);
  }
  printf("%d\n",r.size());
  for(int i=0;i<r.size();i++){
    printf("%d %d %I64d\n",r[i].second.first+1,r[i].second.second+1,r[i].first);
//    cout<<r[i].second.first+1<<" "<<r[i].second.second+1<<" "<<r[i].first<<endl;
  }
}