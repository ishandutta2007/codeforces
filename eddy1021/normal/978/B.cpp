#include <bits/stdc++.h>
using namespace std;
int ans;
char c[111];
int main(){
  int n;
  scanf("%d%s", &n, c);
  for(int i=2; i<n; i++)
    if(c[i] == 'x' and
       c[i-1] == 'x' and
       c[i-2] == 'x')
      ans++;
  cout<<ans<<endl;
}