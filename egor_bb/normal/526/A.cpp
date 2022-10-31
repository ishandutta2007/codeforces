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
 

int main(){
 // ifstream cin (problem".in");
//  ofstream cout(problem".out");
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < 100; i++){
	  for (int j = 0; j < n; j++){
		if (s[j] != '.' && (j + i < n && s[j + i] != '.') && (j + 2 * i < n && s[j + 2 * i] != '.') && (j + 3 * i < n && s[j + 3 * i] != '.') && (j + 4 * i < n && s[j + 4 * i] != '.')){
			cout << "yes\n";
			return 0;
		}
	  }
  }
  cout << "no\n";




}