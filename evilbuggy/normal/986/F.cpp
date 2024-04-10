#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;

const int K = 55;
const int N = 100005;

int vis[N];
long long mini[K][N];
vector<long long> pfac[K];

vector<int> mrt({2, 3, 5, 7, 11, 13, 17, 19, 23});

inline __int128 power(__int128 a, __int128 b, __int128 mod){
	__int128 ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

inline bool checkComposite(__int128 n, __int128 a, __int128 d, int s){
	__int128 x = power(a, d, n);
	if(x == 1 || x == n - 1)return false;
	for(int r = 1; r < s; r++){
		(x *= x) %= n;
		if(x == n - 1)return false;
	}
	return true;
}

inline bool MillerRabin(__int128 n){
	if(n < 4)return (n == 2 || n == 3);
	int s = 0; __int128 d = n - 1;
	while((d & 1) == 0){
		d >>= 1;
		s++;
	}
	for(int a : mrt){
		if(n == a)return true;
		if(checkComposite(n, a, d, s))return false;
	}
	return true;
}

inline long long f(long long x, long long c, long long mod){
	__int128 y = x; y = y*x + c; return y%mod;
}

inline long long pollardRho(long long n, long long x0 = 2, long long c = 1){
	long long x = x0;
	long long y = x0;
	long long g = 1;
	while(g == 1){
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = __gcd(abs(x - y), n);
	}
	return g;
}

inline void getPrimes(long long k, vector<long long> &vec){
	if(MillerRabin(k)){
		vec.emplace_back(k);
		return;
	}
	if(k < 1e11){
		for(long long x = 2; x*x <= k; x++){
			if(k%x == 0){
				while(k%x == 0){
					k /= x;
				}
				vec.emplace_back(x);
			}
		}
		if(k > 1)vec.emplace_back(k);
		return;	
	}
	long long g = pollardRho(k);
	getPrimes(g, vec); getPrimes(k/g, vec);
}

void process(int ind, long long k){
	getPrimes(k, pfac[ind]);
	sort(pfac[ind].begin(), pfac[ind].end());
	pfac[ind].resize(unique(pfac[ind].begin(), pfac[ind].end()) - pfac[ind].begin());

	if(pfac[ind].size() <= 2)return;
	
	memset(vis, 0, sizeof(vis));
	memset(mini[ind], 0x7f, sizeof(mini[ind]));
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, 0}); mini[ind][0] = 0;
	while(!pq.empty()){
		int x = pq.top().second; pq.pop();
		if(vis[x])continue;
		for(int i = 1; i < (int)pfac[ind].size(); i++){
			int nx = (x + pfac[ind][i])%pfac[ind][0];
			if(mini[ind][nx] > mini[ind][x] + pfac[ind][i]){
				mini[ind][nx] = mini[ind][x] + pfac[ind][i];
				pq.push({mini[ind][nx], nx});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	long long n, k;
	map<int, int> indexMap;
	while(t--){
		cin >> n >> k;
		if(!indexMap.count(k)){
			indexMap[k] = (int)indexMap.size();
			process(indexMap[k], k);
		}
		int ind = indexMap[k];
		if(__gcd(n, k) != 1){
			cout << "YES" << '\n';
			continue;
		}
		if(pfac[ind].size() <= 1){
			cout << "NO" << '\n';
		}else if(pfac[ind].size() == 2){
			__int128 p = pfac[ind][0];
			__int128 q = pfac[ind][1];
			__int128 pp = power(p, q - 2, q)*(n%q)%q;
			__int128 qq = power(q, p - 2, p)*(n%p)%p;
			if(pp*p <= n || qq*q <= n){
				cout << "YES" << '\n';
			}else{
				cout << "NO" << '\n';
			}
		}else{
			int x = pfac[ind][0];
			if(mini[ind][n%x] <= n){
				cout << "YES" << '\n';
			}else{
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}