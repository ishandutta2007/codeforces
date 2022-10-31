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



int k;

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> k;
	if (!(k&1)){
		cout << "NO\n";
	}
	else if (k != 1)
	{
		cout << "YES\n" << (k+2)*2 << " " << (k + 2) * k << '\n';
		for (int i = 1; i < k + 2; i++){
			for (int j = i + 1; j < k + 2; j++){
				if (i < k && i & 1 && j - i == 1) continue;
				cout << i << " " << j << '\n';
			}
		}
		for (int i = 1; i < k; i++){
			cout << i << " " << k + 2 << '\n';
		}
		cout << k + 2 << " " << k + 3 << '\n';
		for (int i = k + 4; i < 2 * k + 5; i++){
			for (int j = i + 1; j < 2 * k + 5; j++){
				if (i < 2 * k + 3 && i & 1 && j - i == 1) continue;
				cout << i << " " << j << '\n';
			}
		}
		for (int i = k + 4; i < 2 * k + 3; i++){
			cout << i << " " << k + 3 << '\n';
		}
	} else cout << "YES\n2 1\n1 2\n";

}