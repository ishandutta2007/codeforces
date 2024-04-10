#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


const int M = 2e6+1;
int m[M];

const int N = 40;
int v[N], key[N];

inline void solve(){
    int n; cin>>n;

    int mx = 1;
    int mi = INT_MAX;
    map<int, int> mp;
    bool keep = true;
    for(int i=0; i<n; i++) {
      int&nx = v[i];
        cin>>nx;
        mx = max(mx, nx);
        mi = min(mi, nx);
        if(++mp[nx]>=n/2) keep = false;
    }
    if(!keep){
        cout<<-1<<endl;
        return;
    }



    if(mi<0) mx -= mi;

    while(mx>2){
      int big = mx * (M / mx + 1);
      bool ok = false;
        for(int i=0; i<n; i++) {
          key[i] = (v[i] + big) % mx;
          ok |= ++m[key[i]] >= n / 2;
        }
        for(int i=0; i<n; i++) {
          m[key[i]] = 0;
        }
        if(ok) {
          cout << mx << nl;
          return;
        }
        mx--;
    }
    cout<<2<<nl;

}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin>>t;
  while(t--) solve();

  return 0;
}