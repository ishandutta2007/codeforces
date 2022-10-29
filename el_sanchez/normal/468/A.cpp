#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 100500;                   
                  
int n;

int main() {

	cin >> n;     	
	if (n <= 3) {
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n";
	if ((n - 4) & 1) { //4
		for (int i = 6; i <= n; i += 2) {
			printf("%d - %d = %d\n", i + 1, i, 1);
			printf("%d * %d = %d\n", 1, 1, 1); 	
		}		
		printf("5 * 4 = 20\n");
		printf("3 - 1 = 2\n");
		printf("2 + 2 = 4\n");
		printf("20 + 4 = 24\n");   		
	} else {
		for (int i = 5; i <= n; i += 2) {
			printf("%d - %d = %d\n", i + 1, i, 1);
			printf("%d * %d = %d\n", 1, 1, 1); 	
		}		
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");    		
	}
		
	return 0;
}