#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;

map <pii, int> mp;
int x[1010], y[1010], a[1010], b[1010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int xx = a[i] + x[j], yy = b[i] + y[j];
			mp[mk(xx, yy)]++;
		}
	}
	for (map <pii, int> :: iterator it = mp.begin(); it != mp.end(); it++){
		if (it->se == n){
			printf("%d %d\n", it->fi.fi, it->fi.se);
			return 0;
		}
	}
	return 0;
}