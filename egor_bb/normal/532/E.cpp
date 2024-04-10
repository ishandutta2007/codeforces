#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;



string s, t;
int n, cnt;


void go(int i, int j, int a, int b){
	if (i == n || j == n){
		cnt++;
		return;
	}
	if (s[i] == t[j]) go(i + 1, j + 1, a, b);
	else {
		if (!a){
			go(i + 1, j, 1, b);
		}
		if (!b){
			go(i, j + 1, a, 1);
		}
	}
}


int main(){
 //   ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n >> s >> t;
	go(0, 0, 0, 0);
	cout << cnt << '\n';
}