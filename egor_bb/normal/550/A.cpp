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



string s;

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	getline (cin, s);
	for (int i = 0; i < int(s.size()) - 3; i++){
		if (s[i] == 'A' && s[i + 1] == 'B'){
			for (int j = i + 2; j < int(s.size()) - 1; j++){
				if (s[j] == 'B' && s[j + 1] == 'A'){
					cout << "YES\n";
					return 0;
				}
			}
			break;
		}
	}
	for (int i = 0; i < int(s.size()) - 3; i++){
		if (s[i] == 'B' && s[i + 1] == 'A'){
			for (int j = i + 2; j < int(s.size()) - 1; j++){
				if (s[j] == 'A' && s[j + 1] == 'B'){
					cout << "YES\n";
					return 0;
				}
			}
			break;
		}
	}
	cout << "NO\n";
	return 0;
}