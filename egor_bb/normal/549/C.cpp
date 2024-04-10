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


int n, k, m, a, b;
int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int t; cin >> t;
		if (t & 1) b++;
		else a++;
	}
	k = n - k;
        if(!k){
if (b&1) cout << "Stannis";
else cout << "Daenerys";
} else if (k & 1){
		if (k / 2 >= b || (k / 2 >= a && !((b - (k - a)) & 1))) cout << "Daenerys\n";
		else cout << "Stannis\n";
	} else {
		if ((k + 1) / 2 >= a && ((b - (k - a)) & 1)) cout << "Stannis\n";
		else cout << "Daenerys\n";
	}

}