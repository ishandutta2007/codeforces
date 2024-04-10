#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int inf=1e9;
int n, c, bst[8];
char buf[8];
int main(){
  for(int i=1; i<8; i++) bst[i]=inf;
  scanf("%d", &n); while(n--){
    scanf("%d%s", &c, buf);
    int msk=0;
    for(int i=0; buf[i]; i++)
      msk|=(1<<(buf[i]-'A'));
    bst[msk]=min(bst[msk], c);
  }
  for(int rnd=0; rnd<514; rnd++)
    for(int i=0; i<8; i++)
      for(int j=0; j<8; j++)
        bst[i|j]=min(bst[i|j], bst[i]+bst[j]);
  if(bst[7] == inf) bst[7]=-1;
  cout<<bst[7]<<endl;
}