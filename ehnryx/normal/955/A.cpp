#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES
typedef long long ll; typedef long double ld; typedef pair<int,int> pii; 
typedef complex<ld> pt; typedef vector<pt> pol; typedef mt19937 RNG; const 
char nl = '\n'; const ll INF = 0x3f3f3f3f; const ll INFLL = 0x3f3f3f3f3f3f3f3f; 
const ll MOD = 1e9+7; const ld EPS = 1e-10; int main() { ios::sync_with_stdio(0); 
cin.tie(0);cout.tie(0); cout<<fixed<<setprecision(10); int hr,mn; cin>>hr>>mn; 
ll h,d,c,n; cin>>h>>d>>c>>n; cout<<((hr>=20)?0.8*c*((h+n-1)/n):min((double)
c*((h+n-1)/n),0.8*c*((d*(60*(19-hr)+60-mn)+h+n-1)/n)))<<nl; return 0; }