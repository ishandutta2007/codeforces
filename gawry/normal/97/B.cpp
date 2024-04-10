#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n;
typedef pair<int,int> p2;
p2 t[10000];
vector<p2> s;
void solve(int from,int to){
  if(from+1>=to)return;
//  printf("%d %d\n",from,to);
  int middle=(from+to)/2;
  solve(from,middle);
  solve(middle,to);
  for(int i=from;i<to;i++)s.push_back(p2(t[middle].first,t[i].second));
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d %d",&t[i].first,&t[i].second);
  sort(t,t+n);
  solve(0,n);
  for(int i=0;i<n;i++)s.push_back(t[i]);
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  printf("%d\n",s.size());
  for(int i=0;i<s.size();i++)printf("%d %d\n",s[i].first,s[i].second);
}