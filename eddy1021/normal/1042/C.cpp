#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
vector<int> neg, zer, pos;
int n, a[N];
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    if(a[i] < 0) neg.push_back(i);
    if(a[i] > 0) pos.push_back(i);
    if(a[i] == 0) zer.push_back(i);
  }
  sort(neg.begin(), neg.end(),
       [&](int id1, int id2){
          return a[id1]<a[id2];
       });
  vector<tuple<int,int,int>> op;
  if(zer.size()){
    if(neg.size() % 2){
      op.push_back(make_tuple(1, neg.back(), zer[0]));
      neg.pop_back();
    }
    for(size_t i=1; i<zer.size(); i++)
      op.push_back(make_tuple(1, zer[i], zer[0]));
    if((int)op.size() != n-1)
      op.push_back(make_tuple(2, zer[0], -1));
  }else if(neg.size() % 2){
    op.push_back(make_tuple(2, neg.back(), -1));
    neg.pop_back();
  }
  vector<int> res;
  for(int id: neg) res.push_back(id);
  for(int id: pos) res.push_back(id);
  for(size_t i=1; i<res.size(); i++)
    op.push_back(make_tuple(1, res[i], res[0]));
  for(auto p: op)
    if(get<2>(p) == -1)
      printf("%d %d\n", get<0>(p), get<1>(p)+1);
    else
      printf("%d %d %d\n", get<0>(p), get<1>(p)+1, get<2>(p)+1);
}