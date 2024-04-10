#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5252;
bitset<N> b[N];
int n;
char buf[N];
inline int chg(char ctmp){
  if(isdigit(ctmp)) return ctmp-'0';
  return ctmp-'A'+10;
}
bool sr[N], sc[N];
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s", buf);
    for(int j=0; j<n; j+=4){
      int val=chg(buf[j>>2]);
      for(int k=0; k<4; k++)
        if((val>>(3-k)) & 1)
          b[i][j+k]=1;
    }
  }
  //for(int i=0; i<n; i++, puts(""))
    //for(int j=0; j<n; j++)
      //putchar("01"[b[i][j]]);
  for(int i=0; i+1<n; i++){
    {
      bool ok=true;
      for(int j=0; j<n and ok; j++)
        if(b[i][j] != b[i+1][j])
          ok=false;
      sr[i]=ok;
    }
    {
      bool ok=true;
      for(int j=0; j<n and ok; j++)
        if(b[j][i] != b[j][i+1])
          ok=false;
      sc[i]=ok;
    }
  }
  int ans=1;
  for(int i=n; i>1; i--) if(n%i == 0){
    bool gd=true;
    for(int j=0; j<n and gd; j++){
      if(j%i == i-1) continue;
      if(not sr[j] or not sc[j])
        gd=false;
    }
    if(gd){
      ans=i;
      break;
    }
  }
  printf("%d\n", ans);
}