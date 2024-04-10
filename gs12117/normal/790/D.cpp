#include<cstdio>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
int n;
int a[300100][2];
long long int sa[300100];
long long int sb[300100];
long long int sc[300100];
map<long long int, int> ma;
map<long long int, int> mb;
map<long long int, int> mc;
int ba[300100];
int bb[300100];
int bc[300100];
map<pair<int,int>, int> dpt;
int dp(int x, int y) {
	if (dpt.find(make_pair(x, y)) != dpt.end()) {
		return dpt[make_pair(x, y)];
	}
	int res = 0;
	if (ba[x] >= bb[y] && ba[x] != -1 && dp(ba[x], y) + 1 > res)res = dp(ba[x], y) + 1;
	if (ba[x] <= bb[y] && bb[y] != -1 && dp(x, bb[y]) + 1 > res)res = dp(x, bb[y]) + 1;
	if (bc[min(x, y)] != -1 && dp(bc[min(x, y)], bc[min(x, y)]) + 1 > res)res = dp(bc[min(x, y)], bc[min(x, y)]) + 1;
	dpt[make_pair(x, y)] = res;
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i][1]);
	}
	sa[0] = 0;
	sb[0] = 0;
	sc[0] = 0;
	for (int i = 0; i < n; i++) {
		sa[i + 1] = a[i][0] + sa[i];
		sb[i + 1] = a[i][1] + sb[i];
		sc[i + 1] = a[i][0] + a[i][1] + sc[i];
	}
	for (int i = 0; i <= n; i++) {
		if (ma.find(sa[i]) != ma.end()) {
			ba[i] = ma[sa[i]];
		}
		else {
			ba[i] = -1;
		}
		ma[sa[i]] = i;
		if (mb.find(sb[i]) != mb.end()) {
			bb[i] = mb[sb[i]];
		}
		else {
			bb[i] = -1;
		}
		mb[sb[i]] = i;
		if (mc.find(sc[i]) != mc.end()) {
			bc[i] = mc[sc[i]];
		}
		else {
			bc[i] = -1;
		}
		mc[sc[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		if (ba[i] > ba[i + 1])ba[i + 1] = ba[i];
		if (bb[i] > bb[i + 1])bb[i + 1] = bb[i];
		if (bc[i] > bc[i + 1])bc[i + 1] = bc[i];
	}
	printf("%d", dp(n, n));
	return 0;
}