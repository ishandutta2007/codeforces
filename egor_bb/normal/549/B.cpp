#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <queue>
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
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;


int n, a[105], cnt[105];
string s[105];
vector <int> got;

void add(int i){
	for (int j = 0; j < n; j++) if (s[i][j] == '1') cnt[j]++;
	got.push_back(i + 1);
}

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cout.precision(12);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++){
		if (cnt[i] == a[i]){
			add(i);
			i = -1;
		}
	}
	cout << got.size() << '\n';
	for (int i = 0; i < got.size(); i++) cout << got[i] << " ";
}