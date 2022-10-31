#include <bits/stdc++.h>
using namespace std;
char c[10101];
int n;
int cal(){
  for(int i=1; i<n; i++){
    bool ok=true;
    for(int l=i, r=i+n-1; l<r and ok; l++, r--)
      if(c[l] != c[r])
        ok=false;
    if(not ok) continue;
    ok=false;
    for(int l=i; l<i+n and not ok; l++)
      if(c[l] != c[l-i])
        ok=true;
    if(not ok) continue;
    return 1;
  }
  for(int l=1; l+l<n; l++){
    // ori = c[0:l] + c[l:n-l] + c[n-l:n]
    // now = c[n-l:n] + c[l:n-l] + c[0:l]
    bool ok=true;
    for(int i=n-l, j=l-1; j>=0 and ok; i++, j--)
      if(c[i] != c[j])
        ok=false;
    if(not ok) continue;
    ok=false;
    for(int i=n-l, j=0; j<l and not ok; i++, j++)
      if(c[i] != c[j])
        ok=true;
    if(not ok) continue;
    return 2;
  }
  return -1;
}
int main(){
  scanf("%s", c);
  n=strlen(c);
  for(int i=0; i<n; i++) c[n+i]=c[i];
  int res=cal();
  if(res != -1) printf("%d\n", cal());
  else puts("Impossible");
}