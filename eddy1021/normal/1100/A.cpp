#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=111;
int n, k, a[N];
int s[N], e[N], ss, ee;
int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  for(int i=0; i<n; i++){
    if(a[i] == 1)
      ss++, s[i%k]++;
    else
      ee++, e[i%k]++;
  }
  int ans=0;
  for(int i=0; i<k; i++){
    int ts=ss-s[i];
    int te=ee-e[i];
    ans=max(ans, abs(ts-te));
  }
  cout<<ans<<endl;
}