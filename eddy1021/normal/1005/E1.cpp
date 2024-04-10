#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, m, p[N], a[N];
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    scanf("%d", &p[i]);
    if(p[i]<m) p[i]=-1;
    else if(p[i]>m) p[i]=+1;
    else p[i]=0;
    a[i]=p[i];
    p[i]+=p[i-1];
  }
  LL ans=0;
  unordered_map<int,int> cnt;
  int til=0;
  for(int i=1; i<=n; i++){
    if(a[i]==0){
      while(til<i){
        cnt[p[til]]++;
        til++;
      }
    }
    ans+=cnt[p[i]];
    ans+=cnt[p[i]-1];
    //cerr<<i<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
}