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
 
ll c, hr, hb, wr, wb, ans = 0;


int main(){
 // ifstream cin (problem".in");
//  ofstream cout(problem".out");
  cin >> c >> hr >> hb >> wr >> wb;
  ll k = c / wr;
  for (int i = k; i >= max(0ll, k - 5000000); i--){
	  ans = max(ans, i * hr + ((c - i * wr) / wb) * hb);
  }
  swap(hr, hb);
  swap(wr, wb);
  k = c / wr;
  for (int i = k; i >= max(0ll, k - 5000000); i--){
	  ans = max(ans, i * hr + ((c - i * wr) / wb) * hb);
  }
   
  
  cout << ans << '\n';
}