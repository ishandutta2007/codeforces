#include <bits/stdc++.h>
using namespace std;
const int N=202020;
const int K=11;
int n, k, a[N];
unordered_map<int, int> cnt[K];
inline int cb(int val){
  int ret=0;
  while(val) ret++, val/=10;
  return ret;
}
void add(int val, int dlt){
  int len=cb(val);
  cnt[len][val%k]+=dlt;
}
int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  for(int i=0; i<n; i++)
    add(a[i], 1);
  long long ans=0;
  for(int i=0; i<n; i++){
    add(a[i], -1);
    int tval=a[i]%k;
    for(int j=1; j<K; j++){
      tval=tval*10LL%k;
      int goal=(k-tval)%k;
      auto it=cnt[j].find(goal);
      if(it != cnt[j].end())
        ans+=it->second;
    }
    add(a[i], +1);
  }
  printf("%lld\n", ans);
}