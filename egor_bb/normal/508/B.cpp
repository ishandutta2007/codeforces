#pragma comment (linker, "/STACK:100000000000")
  
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <stack>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
  
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define problem "test"
#define sc second
#define sort stable_sort
const int INF = (1e9 + 7);
const ll INFll = (1e18 + 7);
const int N = 300;
const int NM = 100000;
using namespace std;


int a[10], b[10];

int main(){
  //  ifstream cin (problem".in");
//	ofstream cout (problem".out");
	string s;
	cin >> s;
	bool flag = false;
	for (int i =0 ; i < s.size(); i++){
		if ((s[i] - '0') % 2 == 0){
			flag = true;
			if (!a[s[i] - '0']) a[s[i] - '0'] = i + 1;
			b[s[i] - '0'] = i + 1;;
		}
	}
	if (!flag) cout << -1 ;
	else {
		int mn = INF;
		for (int i = 0; i <= s[s.size() - 1] - '0'; i++){
			if (a[i]) mn = min(mn, a[i]);
		}
		if(mn == INF) {
			int mx = -1;
			for (int j = s[s.size() - 1] - '0'; j < 10; j++) mx = max(mx, b[j]);
			swap(s[mx - 1], s[s.size() - 1]);
		} else {
			swap(s[mn - 1], s[s.size() - 1]);
		}
		cout << s << '\n';
	}
	return 0;
}