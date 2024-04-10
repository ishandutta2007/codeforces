#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <deque>
#include <cassert>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define sort stable_sort
#define psi pair<string, int>
#define pll pair<ll, ll>
#define problem "test"


using namespace std;


string s, t;
int p = 0, n, m, k1, k2;

int main(){
//	ifstream cin (problem".in");
	getline (cin, s);
	getline (cin, t);
	n = s.size(), m = t.size();
	for (int i = 0; i < m; i++){
		if (s[p] == t[i]) p++;
		if (p == n){
			k1 = i;
			break;
		}
	}
	p = n - 1;
	for (int i = m; i >= 0; i--){
		if (s[p] == t[i]) p--;
		if (p < 0){
			k2 = i;
			break;
		}
	}
	cout << max(0, k2 - k1) << '\n';
}