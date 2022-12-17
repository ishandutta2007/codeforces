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

const int N = 300000;
int a[N];
int f[N];
int l[N], r[N];
int ans[N];
pair<int, int> p[N];
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i){
	cin >> a[i];
	p[i] = make_pair(a[i], i);
    }
    sort(p+1, p+1+n);
    memset(ans, 0, sizeof(ans));
    memset(f, 0, sizeof(f));
    for (int i=1; i<=n; ++i) l[i] = r[i] = i;
    for (int i=n; i>=1; --i){
	int id = p[i].second;
	f[id] = 1;
	int nl = id, nr = id;
	if (f[id-1] == 1) nl = l[id-1];
	if (f[id+1] == 1) nr = r[id+1];
	r[nl] = nr;
	l[nr] = nl;
	int len = nr - nl + 1;
	ans[len] = max(ans[len], a[id]);
    }
    for (int i=n; i>=1; --i) ans[i] = max(ans[i], ans[i+1]);
    for (int i=1; i<=n; ++i) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}