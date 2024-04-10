#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, k, a[N];
int main(){
  cin>>n>>k;
  for(int i=0; i<n; i++)
    cin>>a[i];
  sort(a, a+n);
  vector<pair<int,int>> v;
  for(int l=0, r=0; l<n; l=r){
    while(r<n and a[l]==a[r]) r++;
    v.push_back({r-l, a[l]});
  }
  int bl=1, br=n, ba=1;
  while(bl <= br){
    int bmid=(bl+br)>>1;
    int len=0;
    for(auto l: v) len+=l.first/bmid;
    if(len >= k) ba=bmid, bl=bmid+1;
    else br=bmid-1;
  }
  vector<int> ans;
  for(auto l: v){
    int tk=l.first/ba;
    while(tk--) ans.push_back(l.second);
  }
  assert((int)ans.size()>=k);
  ans.resize(k);
  for(auto i: ans)
    cout<<i<<" ";
  cout<<endl;
}