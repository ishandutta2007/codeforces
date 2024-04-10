#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, l;
LL s;
int siz[N], dep[N], a[N];
vector<int> e[N];
void dfs(int v, int fa) {
	siz[v] = 1;
	dep[v] = dep[fa] + 1;
	for(int y : e[v]) {
		if(y != fa) {
			dfs(y, v);
			siz[v] += siz[y];
		}
	}
	sort(e[v].begin(), e[v].end(), [&](int x, int y) { return siz[x] > siz[y]; });
}
map<int, LL> * vec[N];
int ans[N];
LL delta[N];
void calc(int v, int fa) {
	int c = 0;

	for(int y : e[v]) {
		if(y != fa) {
			calc(y, v);
			c += ans[y];
			if(vec[v] == NULL) {
				vec[v] = vec[y];
				delta[v] = delta[y];
			}else {
				for(auto tmp : *vec[y]) {
					tmp.second = tmp.second + delta[y] - delta[v];
					auto itr = vec[v]->upper_bound(tmp.first);
					itr--;
					if(tmp.second >= itr->second) continue;
					(*vec[v])[tmp.first] = tmp.second;
					for(;;) {
						auto itr = vec[v]->upper_bound(tmp.first);
						if(itr == vec[v]->end()) break;
						if(itr->second < tmp.second) break;
						vec[v]->erase(itr);
					}
				}
			}
		}
	}
	if(vec[v] == NULL) {
		vec[v] = new map<int, LL>();
		(*vec[v])[dep[v]] = a[v];
		ans[v] = 1;
		delta[v] = 0;
	}else {
		//cout << "!" << v << endl;
		while(!vec[v]->empty() && (vec[v]->rbegin()->first >= dep[v] + l)) {
			vec[v]->erase(vec[v]->lower_bound(vec[v]->rbegin()->first));
		}
		if(vec[v]->empty() || (vec[v]->rbegin()->second + a[v] + delta[v] > s)) {
			vec[v]->clear();
			(*vec[v])[dep[v]] = a[v] - delta[v];
			ans[v] = c + 1;
		}else {
			delta[v] += a[v];
			(*vec[v])[dep[v]] = s + 1 - delta[v];
			ans[v] = c;
		}
	}
//cout << v << ' ' << ans[v] << endl;
}
int main() {
	cin >> n >> l >> s;
	bool flag = true;
	for(int i(1); i <= n; i++) {scanf("%d", &a[i]); if(a[i] > s) flag = false;}
	if(!flag) {
		printf("-1\n");
		exit(0);
	}
	for(int i(2); i <= n; i++) {
		int y;
		int x = i;
		scanf("%d", &y);
		e[y].pb(x);
	}
	dfs(1, 0);
	calc(1, 0);
	cout << ans[1] << endl;
}