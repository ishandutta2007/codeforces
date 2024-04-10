#include <bits/stdc++.h>
using namespace std;
const int N=505050;
char c[N];
int main(){
  scanf("%s", c);
  int len=strlen(c);
  int lptr=0, rptr=len-1;
  while(lptr<len and c[lptr] != '[') lptr++;
  while(lptr<len and c[lptr] != ':') lptr++;
  while(rptr>=0 and c[rptr] != ']') rptr--;
  while(rptr>=0 and c[rptr] != ':') rptr--;
  if(lptr >= rptr) puts("-1");
  else{
    int ans=4;
    for(int i=lptr; i<=rptr; i++)
      if(c[i] == '|')
        ans++;
    cout<<ans<<endl;
  }
}