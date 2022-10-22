#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[100010];
vector <pii> all;
int L, b, f;

void Update(int l, int r, int x){
	for (int i = l; i <= r; i++){
		a[i] += x;
	}
}

int Query(int x){
	int sum = 0, cnt1 = b, cnt2 = 0;
	for (int i = 0; i < L; i++){
		if (a[i] == 0) sum++;
		else sum = 0;
		if (cnt2 < i) cnt2 = i;
		if (i == cnt2) while (cnt2 < L && a[cnt2] == 0) cnt2++;
		if (i - x >= 0 && a[i - x] == 1) cnt1 = 0;
		else cnt1++;
//		cout << "i:" << i << " " << cnt1 << " " << cnt2 - i << endl;
		if (sum >= x && cnt1 >= b && (cnt2 - i - 1 >= f || cnt2 == L)) return i - x + 1;
	}
	return -1;
}

int main(){
	scanf("%d%d%d", &L, &b, &f);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int op, x; scanf("%d%d", &op, &x);
		if (op == 1){
			int pos = Query(x);
			if (pos != -1) Update(pos, pos + x - 1, 1);
			all.push_back(mp(pos, pos + x - 1));
			printf("%d\n", pos);
		} else {
			all.push_back(mp(-1, -1));
			if (all[x - 1].fi != -1) Update(all[x - 1].fi, all[x - 1].se, -1);
		}
	}
	return 0;
}