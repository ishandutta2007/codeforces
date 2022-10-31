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
int n;

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> s;
	s = "00" + s;
	n = s.size();
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			for (int k = j + 1; k < n; k++){
				if (((s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0')) % 8 == 0){
					cout << "YES\n";
					if (s[i] != '0') cout << s[i] << s[j] << s[k] << '\n';
					else if (s[j] != '0') cout << s[j] << s[k] << '\n';
					else cout << s[k] << '\n';
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}