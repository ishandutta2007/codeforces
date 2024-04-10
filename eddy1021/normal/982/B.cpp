#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, w[N];
char c[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &w[i]);
  vector< pair<int,int> > cand;
  for(int i=1; i<=n; i++)
    cand.push_back({w[i], i});
  sort(cand.begin(), cand.end());
  reverse(cand.begin(), cand.end());
  priority_queue< pair<int,int> > heap;
  scanf("%s", c);
  for(int i=0; c[i]; i++){
    if(c[i] == '0'){
      printf("%d ", cand.back().second);
      heap.push(cand.back());
      cand.pop_back();
    }else{
      printf("%d ", heap.top().second);
      heap.pop();
    }
  }
  puts("");
}