#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lli;

const int SIZE = 1005;

vector<int> primes;
bool visited[SIZE];

int main() {
	int n, kw;
	scanf("%d %d", &n, &kw);
	for(int i = 2; i <= n + 1; i++) if(!visited[i]) {
		for(int j = i*i; j <= n + 1; j += i) visited[j] = true;
		primes.push_back(i);
	}
	int k = 0;
	for(int i = 0; i < primes.size(); i++) {
		for(int j = 0; j < i-1; j++) {
			if(primes[j] + primes[j+1] + 1 == primes[i]) {
				k++;
				break;
			}
		}
		if(k == kw) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}