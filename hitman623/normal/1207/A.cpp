#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solve(){
  int b,p,f;
  cin>>b>>p>>f;
  int h,c;
  cin>>h>>c;
  if(h>c){
    int ham=min(p,b/2);
    b-=2*ham;
    int chicken=min(f,b/2);
    cout<<ham*h+chicken*c<<endl;
  }
  else{
    int chicken=min(f,b/2);
    b-=2*chicken;
    int ham=min(p,b/2);
    cout<<ham*h+chicken*c<<endl;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}