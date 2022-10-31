#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define mp make_pair
#define problem "test"

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 200005;

using namespace std;

bool cmp(pii a, pii b){
	return (a.F < b.F || (a.F == b.F && (abs(a.S) < abs(b.S))));
}

int n, q, ans[200005], x, y, t;
char c;
pii a[200005], s[200005];

int main(){
	scanf("%d%d", &n, &q); n++;
	for (int i = 0; i < q; i++){
		scanf ("%d%d %c", &x, &y, &c);
		if (c == 'L') a[i] = mp(x, -(i + 1));
		else a[i] = mp(x, i + 1);
	}
	sort (a, a + q, &cmp);
	for (int i = 0; i < q; i++){
                if (i && (a[i - 1].F == a[i].F)){
                    ans[abs(a[i].S)] = 0;
                    continue;
                }
		if (a[i].S < 0){
			while (t && (s[t - 1].S > -a[i].S)){
				ans[s[t - 1].S] = a[i].F - s[t - 1].F;
				t--;
			}
			if (t){
				ans[-a[i].S] = a[i].F - s[t - 1].F;
			} else {
				ans[-a[i].S] = a[i].F;
			}
		} else s[t++] = a[i];
	}
	while (t){
		ans[s[t - 1].S] = n - s[t - 1].F;
		t--;
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}