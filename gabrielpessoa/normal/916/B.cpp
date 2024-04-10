#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 2E5+5;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int arr[SIZE];

int main() {
	ll n;
	int k;
	cin >> n >> k;
	int idx = DELTA;
	int menor = INF, maior = 0;
	while(n) {
		if(n & 1ll) {
			arr[idx]++;
			k--;
			menor = min(menor, idx);
			maior = max(maior, idx);
		}
		//cout << n << " >> 1 = " << (n >> 1) << endl;
		n >>= 1;
		idx++;
	}
	if(k < 0) {
		printf("No\n");
		return 0;
	}
	while(k > 0) {
		if(arr[maior] <= k) {
			arr[maior-1] += arr[maior] * 2;
			k -= arr[maior];
			arr[maior] = 0;
			maior--;
			if(arr[menor] == 0) menor--;
			//printf("maior agora eh %d e temos %d dele\n", maior - DELTA, arr[maior]);
		} else {
			arr[menor-1] += 2;
			k--;
			arr[menor]--;
			menor--;
			if(arr[maior] == 0) maior--;
		}
	}
	printf("Yes\n");
	for(int i = maior; i >= menor; i--) {
		while(arr[i]--) printf("%d ", i-DELTA);
	}
	return 0;
}