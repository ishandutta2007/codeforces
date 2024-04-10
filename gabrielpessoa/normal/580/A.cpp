#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int arr[SIZE];

int main() {
	int n, atual = 0, best = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if(arr[i] < arr[i-1]) {
			atual = 1;
		} else {
			best = max(best, ++atual);
		}
	}
	printf("%d\n", best);
	return 0;
}