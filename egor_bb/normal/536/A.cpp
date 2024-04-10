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
 


ll a, b, n, l, t, m, h[3000000], f[3000000];

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
  cin >> a >> b >> n;
  h[1] = a;
  for (int i = 2; i < 2000000; i++){
	  h[i] = h[i - 1] + b;
  }
  for (int i = 0;i < n; i++){;
	  ll mm;
	  cin >> l >> t >> mm;
	  if (t < h[l]) cout << -1 << '\n';
	  else {
		  ll lf = l, r = 2000000;
		  while (r - lf > 1){
			  ll m = (lf + r) / 2;
			  if ((h[m] + h[l]) * (m - l + 1) / 2 > t * mm || t < h[m]) r = m;
			  else lf = m;
		  }
		  cout << lf << '\n';
	  }
  }


}