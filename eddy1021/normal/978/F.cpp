#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, k, r[N], ans[N];
int main(){
  scanf("%d%d", &n, &k);
  vector<int> v;
  for(int i=1; i<=n; i++){
    scanf("%d", &r[i]);
    v.push_back(r[i]);
  }
  while(k--){
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    if(r[ai] < r[bi]) ans[bi]--;
    if(r[bi] < r[ai]) ans[ai]--;
  }
  sort(v.begin(), v.end());
  for(int i=1; i<=n; i++){
    int bl=0, br=n-1, a=-1;
    while(bl <= br){
      int mid=(bl+br)>>1;
      if(v[mid]<r[i]) a=mid, bl=mid+1;
      else br=mid-1;
    }
    ans[i]+=a+1;
  }
  for(int i=1; i<=n; i++)
    printf("%d%c", ans[i], " \n"[i == n]);
}