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




int ok[100][100], n, m;
char a[100][100];
vector <int> p[2];
int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 'o'){
				p[0].push_back(i);
				p[1].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0 ; j < n; j++){
			if (a[i][j] == '.'){
				for (int k = 0; k < p[0].size(); k++){
					ok[p[0][k] - i + n - 1][p[1][k] - j + n - 1] = 1;
				}
			}
		}
	}	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == 'x'){
				bool kk = 0;
				for (int k = 0; k < p[0].size(); k++){
					if (!ok[p[0][k] - i + n - 1][p[1][k] - j + n - 1]){
						kk = 1;
						break;
					}
				}
				if (!kk){
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
		cout << "YES\n";
		for (int i = 2 * n - 2; i >= 0; i--){
			for (int j = 2 * n - 2; j >= 0; j--){
				if (i == j && i == n - 1){
					cout << 'o';
					continue;
				}
				if (ok[i][j]) cout << '.';
				else cout << 'x';
			}
			cout << '\n';
		}
}