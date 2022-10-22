#include <bits/stdc++.h>

using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };



ll mod_pow(ll x, ll p, ll M = INF) {
  ll a = 1;
  while (p) {
    if (p % 2)
      a = a*x%M;
    x = x*x%M;
    p /= 2;
  }
  return a;
}

bool cmp(pll a, pll b) {
  return a.first - a.second > b.first - b.second;
}
  
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<pll> x(n);
  rep (i, n) {
    cin >> x[i].first >> x[i].second;
  }
  sort(all(x), cmp);
  ll sum = 0;
  bool owari = false;
  ll las = 0;
  rep (i, n) {
    //DEBUG(sum);
    if (i < b) {
      //DEBUG(i);
      //DEBUG(b);
      if (x[i].first > x[i].second) {
	sum += x[i].first;
	if (i == b - 1) {
	  owari = true;
	  las = x[i].first - x[i].second;
	}
	continue;
      }
    }
    sum += x[i].second;
  }
  if (b == 0) {
    cout << sum << endl;
    return 0;
  }
  ll bai = mod_pow(2, a);
  ll ans = sum;
  //DEBUG(ans);
  rep (i, n) {
    //cout <<i << "; ";
    ll score = sum;
    if (i < b) {
      score -= max(x[i].first, x[i].second);
      score += max(x[i].first * bai, x[i].second);
    }
    else {
      score -= x[i].second;
      if (owari) {
	score -= las;
      }
      score += max(x[i].first * bai, x[i].second);
    }
    ans = max(ans, score);
    //DEBUG(score);
  }
  cout << ans << endl;
}
      
    
/*
10
2 5
6 2
100 1
50 100
2 52
7 1
15 3
3 7
1 1
3 30
80 56
//*/