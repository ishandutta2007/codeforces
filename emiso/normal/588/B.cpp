#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool lovely(vector<ll> v) {
  for(int i=1;i<v.size();i++)
    if(v[i] == v[i-1]) return 0;
  return 1;
}

vector<ll> getdiv(ll a) {
  vector<ll> ans;
  for(ll i=1; i*i <= a; i++) {
    if(a%i == 0) {
      ans.push_back(i);
      ans.push_back(a/i);
    }
  }
  ans.at(0);
  return ans;
}

vector<ll> getprimediv(ll a) {
  vector<ll> ans;
  ans.push_back(1);
  for(ll i=2;i*i<=a;i++) {
    while(a%i==0) {
      ans.push_back(i);
      a/= i;
    }
  }
  if(a > 1) ans.push_back(a);
  return ans;
}

int main() {
  ll n,ans=-1;
  scanf("%lld",&n);
  vector<ll> v = getdiv(n);
  for(int i = 0; i < v.size(); i++) {
    if(lovely(getprimediv(v[i]))) {
      if(v[i] > ans) ans = v[i];
    }
  }
  printf("%lld\n",ans);
  return 0;
}