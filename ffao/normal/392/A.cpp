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

long long n;

int main() {
	cin >> n;
	
	long long ans = 0;
	long long k = 0;
	long long pk = 0;
	for (long long i = n; i >= 0; i--) {
		while ((k+1)*(k+1) + i*i <= n*n) {
			k++;
			ans += i==0 ? 2 : 4;
		}

		if (k == pk) {
			ans += i==0 ? min(2LL, 2*k+1) : min(4LL, 4*k+2);
		}

		pk = k;
	}

	cout << ans << endl;
}