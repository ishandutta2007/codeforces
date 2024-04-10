#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
int n;
char a[N], b[N];
int cal(char a1, char a2, char b1, char b2){
  map<char,int> cnt;
  cnt[a1]++; cnt[a2]++;
  cnt[b1]++; cnt[b2]++;
  vector<int> vc;
  for(auto i: cnt) vc.push_back(i.second);
  sort(vc.begin(), vc.end());
  if(vc.size() == 1u) return 0;
  if(vc.size() == 4u) return 2;
  if(vc.size() == 2u){
    if(vc[0] == 2) return 0;
    return 1;
  }
  if(a1 == a2) return 2;
  return 1;
}
int main(){
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  int ans=0;
  for(int l=0, r=n-1; l<=r; l++, r--){
    if(l == r){
      if(a[l] != b[r]) ans++;
      continue;
    }
    ans+=cal(a[l], a[r], b[l], b[r]);
  }
  cout<<ans<<endl;
}