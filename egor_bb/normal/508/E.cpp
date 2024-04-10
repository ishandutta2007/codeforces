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


int n, l[605], r[605];
vector <int> ok, ok2;
string s = "", s2 = "";

int main(){
//   ifstream cin (problem".in");
//	ofstream cout (problem".out");
	cin >> n;
	for (int i = 0 ; i < n; i++){
		cin >> l[i] >> r[i];
	}
	ok.push_back(1);
	for (int i = n - 1; i >= 0; i--){
		bool flag = false;
		for (int j = 0; j < ok.size(); j++){
			if (ok[j] >= l[i] && ok[j] <= r[i]){
				int ff = ok[j];
				flag = true;
				ok2.push_back(1);
				for (int q = j; q < ok.size(); q++){
					ok2.push_back(ok[q] + 2);
				}
				ok = ok2;
				ok2.clear();
				s2 = "(";
				for (int q = 0; q < ff - 1; q++){
					s2.push_back(s[q]);
				}
				s2.push_back(')');
				for (int q = ff - 1; q < s.size(); q++){
					s2.push_back(s[q]);
				}
				s = s2;
				s2.clear();
				break;
			}
		}
		if (!flag){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << s << '\n';
	return 0;
}