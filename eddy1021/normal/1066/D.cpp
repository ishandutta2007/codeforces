#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, m, k, a[N];
int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  int res=k, ans=0;
  for(int i=n-1; i>=0; i--){
    if(a[i] > res) res=k, m--;
    if(m==0) break;
    if(a[i] > res) break;
    res-=a[i];
    ans++;
  }
  cout<<ans<<endl;
}