#include <bits/stdc++.h>
using namespace std;
const int N=202020;
const int Z=26;
int s[N], k;
char a[N];
int main(){
  scanf("%d", &k);
  for(int _=0; _<2; _++){
    scanf("%s", a);
    for(int i=0; i<k; i++)
      s[i]+=a[i]-'a';
  }
  for(int i=k-1; i>0; i--){
    s[i-1]+=s[i]/Z;
    s[i]%=Z;
  }
  for(int i=0; i<k; i++){
    if(s[i] % 2) s[i+1]+=Z;
    s[i]>>=1;
    putchar('a'+s[i]);
  }
  puts("");
}