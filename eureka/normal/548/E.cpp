#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

typedef long long lld;

const int N = 600000;
int a[N];
int f[N];

const int pn = 600000;
int mark[pn];
int p[pn];
int prime(int n = pn-1){
    int num = 0, i, j;
    memset(mark, 0, sizeof(mark));
    for(i=2; i<=n; i++){
	if(!mark[i]) mark[i] = p[num++] = i;
	for(j=0; j<num && i*p[j]<n; j++){
	    mark[i*p[j]] = p[j];
	    if(i%p[j] == 0) break;
	}
    }
    return num;
}

int cnt[N];

lld dfs(int c, int f, int n, int m){
    //    cout << ":" << c << ' ' << m << ' ' << cnt[c] * f << endl;
    lld ans = 0;
    if (n != 1){
	int fac = mark[n];
	while (n % fac == 0) n /= fac;
	ans += dfs(c, f, n, m);
	ans += dfs(c*fac, f*-1, n, m);
    }else{
	ans = cnt[c] * f;
	cnt[c] += m;
    }
    return ans;
}

int main(){
    prime();
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; ++i) cin >> a[i];
    memset(f, 0, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    lld ans = 0;
    for (int i=0; i<q; ++i){
	int x;
	cin >> x;
	int m = f[x] == 0 ? 1 : -1;
	f[x] ^= 1;
	ans += m * dfs(1, 1, a[x], m);
	if (m == -1 && a[x] == 1) ans ++;
	cout << ans << endl;
    }
    return 0;
}