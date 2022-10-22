#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long

const int N=100+7;
int n,fibo[N],fibo_prefix[N];
pair<int, int> v[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  ///freopen ("___input___.txt", "r", stdin);

  fibo[1]=1;
  fibo[2]=1;
  for (int i=3;i<N;i++) {
    fibo[i]=fibo[i-1]+fibo[i-2];
  }
  for (int i=1;i<N;i++){
    fibo_prefix[i]=fibo_prefix[i-1]+fibo[i];
  }


  if (0) {
    for (int i=1;i<N;i++){
      cout<<fibo_prefix[i]-fibo[i+2]<<"\n"; /// -1
    }
    exit(0);
  }

  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    cin>>n;
    for (int i=1;i<=n;i++) {
      cin>>v[i].first;
      v[i].second=i;
    }
    sort(v+1,v+n+1);
    int total_sum=0;
    for (int i=1;i<=n;i++){
      total_sum+=v[i].first;
    }
    int cnt=0;
    while(fibo_prefix[cnt]<total_sum){
      cnt++;
    }
    if(fibo_prefix[cnt]>total_sum){
      cout<<"NO\n";
      continue;
    }
    int last=-1;
    bool ok=1;
    for (int ite=cnt;ite>=1;ite--){
      int x=fibo[ite];
      sort(v+1,v+n+1);
      reverse(v+1,v+n+1);
      bool f=0;
      int cnt=0;
      for (int i=1;i<=n;i++){
        cnt+=(v[i].first>=x);
      }
      for (int i=1;i<=n;i++) {
        if(v[i].first>=x&&v[i].second!=last){
          last=v[i].second;
          f=1;
          v[i].first-=x;
          break;
        }
      }
      if(!f){
        ok=0;
      }
    }
    cout<<((ok)?("YES"):("NO"))<<"\n";
  }

}