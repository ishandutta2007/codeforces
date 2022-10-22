#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n,q,a[N],dim;
bool prime[N];
vector<int> divi;
__gnu_pbds::priority_queue<ll> qq;
vector<__gnu_pbds::priority_queue<ll>> s;
vector<vector<decltype(qq)::point_iterator>> iters;
vector<vector<ll>> sum;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  prime[2]=1;
  for (int i=3;i<N;i+=2){
    prime[i]=1;
  }
  for(int i=3;i*i<N;i+=2){
    if(prime[i]){
      for(int j=i*i;j<N;j+=2*i)prime[j]=0;
    }
  }


  int tests;
  cin>>tests;
  for(int tc=1;tc<=tests;tc++){
    cin>>n>>q;
    divi.clear();
    sum.clear();
    s.clear();
    iters.clear();
    for (int i=1;i<=n;i++){
      if(n%i==0){
        if(i>1&&!prime[n/i]) continue;
        if(i==n) continue;
        divi.push_back(i);
        sum.push_back(vector<ll>(i,0LL));
        s.push_back({});
        iters.push_back({});
        iters.back().reserve(i);
      }
    }
    dim=(int)divi.size();
    ll sol=0;
    for (int i=0;i<n;i++) {
      cin>>a[i];
      for (int ite=0;ite<dim;ite++){
        sum[ite][i%divi[ite]]+=(ll)divi[ite]*a[i];
      }
    }
    for (int ite=0;ite<dim;ite++){
      for (int i=0;i<divi[ite];i++) {
        iters[ite].push_back(s[ite].push(sum[ite][i]));
        sol=max(sol,s[ite].top());
      }
    }
    cout<<sol<<"\n";
    for (int iq=1;iq<=q;iq++){
      int i,x;
      cin>>i>>x;
      i--;
      sol=0;
      for (int ite=0;ite<dim;ite++){
        sum[ite][i%divi[ite]]+=(ll)divi[ite]*(x-a[i]);
        s[ite].modify(iters[ite][i%divi[ite]],sum[ite][i%divi[ite]]);
        sol=max(sol,s[ite].top());
      }
      a[i]=x;
      cout<<sol<<"\n";
    }
  }

}