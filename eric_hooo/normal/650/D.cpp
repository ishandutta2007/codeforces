#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

inline char nc(){
    static char buf[30000000],*p1=buf,*p2=buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 30000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char ch = nc();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9')) ch = nc();
    while (ch >= '0' && ch <= '9') sum = (sum << 1) + (sum << 3) + (ch ^ '0'), ch = nc();
    return sum;
}

void print(int a) {
    if (a > 9) print(a / 10);
    putchar(a % 10 + '0');
}

typedef pair <int, int> pii;

int a[400010];
vector <pair <int, int> > all[400010];
vector <int> l[400010], r[400010];
vector <int> id;
int cnt[400010];
int T[800010];
int pd[400010], ans[400010], f[400010], g[400010];
int n, m;
vector <int> v[400010];

void add(int x, int v){
	while (x <= id.size()){
		T[x] = max(T[x], v);
		x += x & -x;
	}
}

int sum(int x){
	int res = 0;
	while (x){
		res = max(res, T[x]);
		x -= x & -x;
	}
	return res;
}

int main(){
	memset(cnt, -1, sizeof(cnt));
	n = read(), m = read();
	for (int i = 0; i < n; i++){
		a[i] = read();
		id.push_back(a[i]);
	}
	for (int i = 0; i < m; i++){
		int pos = read(), x = read();
		id.push_back(x);
		all[pos - 1].push_back(mp(x, i));
	}
	id.push_back(0);
	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end()) - id.begin());
//	cout << "a:";
	for (int i = 0; i < n; i++){
		a[i] = lower_bound(id.begin(), id.end(), a[i]) - id.begin();
//		cout << a[i] << " ";
		for (int j = 0; j < all[i].size(); j++){
			all[i][j].fi = lower_bound(id.begin(), id.end(), all[i][j].fi) - id.begin();
		}
	}
//	cout << endl;
//	cout << "		   lis:" << lis << endl;
	memset(T, 0, sizeof(T));
	for (int i = 0; i < n; i++){
		f[i] = sum(a[i] - 1);
		for (int j = 0; j < all[i].size(); j++){
			l[i].push_back(sum(all[i][j].fi - 1));
		}
		add(a[i], sum(a[i] - 1) + 1);
	}
	int lis = sum(id.size() - 1);
	memset(T, 0, sizeof(T));
	for (int i = n - 1; i >= 0; i--){
		g[i] = sum(id.size() - a[i] - 1);
		for (int j = 0; j < all[i].size(); j++){
			r[i].push_back(sum(id.size() - all[i][j].fi - 1));
		}
		add(id.size() - a[i], sum(id.size() - a[i] - 1) + 1);
	}
	memset(cnt, -1, sizeof(cnt));
	for (int i = 0; i < n; i++){
		if (f[i] + g[i] + 1 != lis){
			pd[i] = 1;
			continue;
		}
		if (cnt[f[i]] == -1) cnt[f[i]] = i;
		else if (cnt[f[i]] == -2) pd[i] = 1;
		else if (cnt[f[i]] != i) pd[i] = 1, pd[cnt[f[i]]] = 1, cnt[f[i]] = -2;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < all[i].size(); j++){
			ans[all[i][j].se] = max(l[i][j] + r[i][j] + 1, lis - (1 - pd[i]));
		}
	}
//	cout << "important:";
//	for (int i = 0; i < n; i++){
//		if (!pd[a[i]]) cout << i + 1 << " ";
//	}
//	cout << endl;
	for (int i = 0; i < m; i++){
		print(ans[i]), putchar('\n');
	}
	return 0;
}