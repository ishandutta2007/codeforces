#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define ll long long
#define db double
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define mpll map<ll, ll>
#define mcll map<char,ll>
#define mpll_p map<ll, pair<ll, ll>>
#define mp_pll map<pair<ll, ll>, ll>
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define vtll vector<tuple<ll,ll,ll>> 
#define vs vector<string>
#define vc vector<char>
#define sll set<ll>
#define spll set<pair<ll, ll>>
#define pi 3.14159265358979323846264338327
#define nope string::npos
void fast(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool primecheck(ll n){
  for(ll i=2;i<=sqrt(n);i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
int main(){
  fast();
  ll t; cin>>t;
  vector<bool> prime(1000001,1);
  for(ll i=2;i*i<=1000000;i++){
    if(prime[i]){
      for(ll j=i*i;j<=1000000;j+=i){
        prime[j]=0;
      }
    }
  }
  vector<int> m(1000001);
  ll cnt=0;
  ll cntpt=0;
  ll pt=1;
  for(ll i=1;i<=1000000;i++){
    if(prime[i]){
      cnt++;
    }
    while(i>=pt*pt)
    {
        if(prime[pt])
            cntpt++;
        pt++;
    }
    m[i]=cnt-cntpt;
  }
  while (t--)
  {
    ll x; cin>>x;
    cout<<m[x]+1<<'\n';
  }
}