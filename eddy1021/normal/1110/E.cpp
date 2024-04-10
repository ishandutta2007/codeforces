#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
LL n, a[N], b[N];
int main(){
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<n; i++) cin>>b[i];
  vector<LL> c, d;
  for(int i=1; i<n; i++){
    c.push_back(a[i]-a[i-1]);
    d.push_back(b[i]-b[i-1]);
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  puts(a[0]==b[0]and c==d?"Yes":"No");
}