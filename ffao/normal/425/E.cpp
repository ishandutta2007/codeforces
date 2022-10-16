#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

const int mod = 1000000007;
long long dp[510][510];
long long pot[300000];
int n,k;

long long sub(long long a, long long b) {
	return (((a-b) % mod) + mod) % mod;
}

int calc(int pe, int put) {
	long long &ret = dp[pe][put];

	if (ret == -1) {
		ret = 0;
		if (put == k) {
			ret = pot[(n-pe) * pe];
		}

		else {
			for (int ne = pe+1; ne <= n; ne++) {
				long long term = pot[(ne-pe-1) * pe] % mod;
				term = (term * sub(pot[ne], pot[pe])) % mod;
				term = (term * calc(ne, put+1)) % mod;

				ret = (ret + term) % mod;
			}
		}
	}

	return ret;
}

int main() {
	cin >> n >> k;
	memset(dp,-1,sizeof(dp));
	pot[0] = 1;
	for (int i = 1; i <= 275000; i++) {
		pot[i] = (pot[i-1] * 2) % mod;
	}
	cout << calc(0, 0) << endl;
}