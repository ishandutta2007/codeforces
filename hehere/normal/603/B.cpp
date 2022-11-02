#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include <algorithm>
#include <set>
using std::set; using std::multiset;
#include <map>
using std::map;
#include <bitset>
using std::bitset;
typedef long long LL;

const LL maxP = 1000000 + 233;
const LL MOD = 1000000007;
LL p, k;
bool vis[maxP];

bool spj() {
    if(k == 0) {
        LL ans = 1;
        for(int i = 0; i < p - 1; ++i) ans = ans * p % MOD;
        cout << ans << endl;
        return true;
    } else if(k == 1) {
        LL ans = 1;
        for(int i = 0; i < p; ++i) ans = ans * p % MOD;
        cout << ans << endl;
        return true;
    } else {
        return false;
    }
}

//int f[maxP];
//int tot = 0;
//void dfs(int u) {
//    if(u == p) {
//        for(int i = 0; i < p; ++i) if(f[i * k % p] != k * f[i] % p) return;
//        ++tot;
//        return;
//    }
//    for(int i = 0; i < p; ++i) {
//        f[u] = i;
//        dfs(u + 1);
//    }
//}

int main() {
	cin >> p >> k;
//	dfs(0); cout << tot << " is ans" << endl;
	if(spj()) return 0;
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	for(int i = 1; i < p; ++i) if(!vis[i]) {
//	    printf("new round : i = %d ", i);
		int x = i;
		while(!vis[x]) vis[x] = true, x = x * k % p/*, printf("%d ", x)*/;
//        printf("\n");
		++cnt;
	}
	LL ans = 1;
	while(cnt--) ans = ans * p % MOD;
	cout << ans << endl;
	return 0;
}