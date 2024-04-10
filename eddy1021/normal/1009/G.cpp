// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int K=6;
const int N=101010;
char c[N], ans[N];
int n, msk[N], cnt[K];
int tot[1<<K], tot2[1<<K];
void no(){
  puts("Impossible");
  exit(0);
}
bool good(){
  for(int i=0; i<(1<<K); i++) tot2[i]=tot[i];
  for(int i=0; i<K; i++)
    for(int j=0; j<(1<<K); j++)
      if((j>>i)&1)
        tot2[j]+=tot2[j^(1<<i)];
  for(int i=1; i<(1<<K); i++){
    int gt=0;
    for(int j=0; j<K; j++)
      if((i>>j)&1)
        gt+=cnt[j];
    if(gt<tot2[i])
      return false;
  }
  return true;
}
void solve(){
  for(int i=0; i<n; i++){
    int ok=-1;
    tot[msk[i]]--;
    for(int j=0; j<6; j++){
      cnt[j]--;
      if(((msk[i]>>j)&1) and good()){
        ok=j;
        break;
      }
      cnt[j]++;
    }
    if(ok==-1) no();
    ans[i]=(char)('a'+ok);
  }
  puts(ans);
}
int main(){
  scanf("%s", c);
  for(int i=0; c[i]; i++) cnt[c[i]-'a']++;
  n=strlen(c);
  for(int i=0; i<n; i++) msk[i]=(1<<K)-1;
  int m; scanf("%d", &m); while(m--){
    int k; scanf("%d%s", &k, c); k--;
    msk[k]=0;
    for(int i=0; c[i]; i++) msk[k]|=(1<<(c[i]-'a'));
  }
  for(int i=0; i<n; i++) tot[msk[i]]++;
  solve();
}