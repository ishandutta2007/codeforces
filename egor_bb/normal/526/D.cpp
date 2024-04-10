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
 
string s;
int n, k;

vector <int> ok, pk;

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".out");
  cin >> n >> k >> s;
  ok.resize(n, 0);
  pk.resize(n, 0);
  vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	vector<int> p (n);
	for (int i=1; i<n; ++i) {
		int j = p[i-1];
		while (j > 0 && s[i] != s[j])
			j = p[j-1];
		if (s[i] == s[j])  ++j;
		p[i] = j;
	}
	for (int i = k - 1; i < n; i += k) {
		if (k == 1) pk[i] = 1;
		if (((i + 1) % (i + 1 - p[i])) == 0 && (((i + 1) / k) % (i + 1 - p[i])) == 0){
			pk[i] = 1;	
		}
	}
	
	for (int i = n - 1; i >= 0; i--){
		if (pk[i]){
			ok[i] = 1;
			for (int j = i + 1; j <= i + (i + 1) / k && j < n && j <= i + z[i + 1]; j++){
				if (ok[j]) break;
				ok[j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << ok[i];

}