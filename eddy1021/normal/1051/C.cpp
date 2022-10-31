#include <bits/stdc++.h>
using namespace std;
const int N=111;
int n;
vector<int> id[N];
char ans[N];
int main(){
  scanf("%d", &n);
  for(int i=0, j; i<n; i++){
    scanf("%d", &j);
    id[j].push_back(i);
  }
  vector<int> one;
  int more=0;
  for(int i=0; i<N; i++){
    if(id[i].empty()) continue;
    if(id[i].size()==1u){
      one.push_back(id[i].back());
      id[i].pop_back();
      continue;
    }
    if(id[i].size() == 2u) continue;
    more=i;
  }
  if(one.size()%2){
    if(more==0){
      puts("NO");
      exit(0);
    }
    one.push_back(id[more].back());
    id[more].pop_back();
  }
  for(int i=0; i<n; i++) ans[i]='A';
  for(size_t i=1; i<one.size(); i+=2) ans[one[i]]='B';
  puts("YES");
  puts(ans);
}