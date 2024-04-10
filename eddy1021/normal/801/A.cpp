#include <bits/stdc++.h>
using namespace std;
char c[111],p;
int f(){
  int s=0;p=0;
  for(int i=0;c[i];i++){
    s+=(p=='V' and c[i]=='K');
    p=c[i];
  }
  return s;
}
int main(){
  scanf("%s",c);
  int ans=f();
  for(int i=0;c[i];i++){
    c[i]=c[i]=='V'?'K':'V';
    ans=max(ans,f());
    c[i]=c[i]=='V'?'K':'V';
  }
  printf("%d\n",ans);
}