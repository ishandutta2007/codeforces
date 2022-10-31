#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
 
 
const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
 
using namespace std;
 

string s, p;
ll n, m, a[1000005], ls = -1, now = 0, ans = 1;

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
  cin >> n >> m;
  cin >> p;
  for (int i = 0; i < m; i++) cin >> a[i];
  
  vector<int> z (p.size());
	for (int i=1, l=0, r=0; i<p.size(); ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && p[z[i]] == p[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}

  for (int i = 0; i < n; i++){
	  if (a[now] == i + 1){
		  if (now){
			  if (a[now] - a[now - 1] >= p.size()) now++;
			  else  if (z[(a[now] - a[now - 1])] >= p.size() - (a[now] - a[now - 1])) now++;
			  else {
				  cout << 0 << '\n';
				  return 0;
			  }
		  }
		  else now++;
	  }
	  else if (!now || a[now - 1] + int(p.size()) <= i + 1){
		  ans = (ans * 26) % INF;
	  }
  }
  cout << ans << '\n';


}