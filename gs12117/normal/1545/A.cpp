#include<cstdio>
#include<algorithm>
int n;
int a[100100];
int cnt[100100][2];
struct st {
	int x, oddeven;
	bool operator<(const st&r)const {
		return x < r.x;
	}
};
st sl[100100];
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			sl[i].x = a[i];
			if (i % 2 == 0) {
				sl[i].oddeven = 1;
			}
			else {
				sl[i].oddeven = -1;
			}
		}
		std::sort(sl, sl + n);
		int sumo = 0;
		int flag = 0;
		for (int l = 0; l < n; ) {
			int r = l;
			while (r < n&&sl[l].x == sl[r].x) {
				sumo += sl[r].oddeven;
				r++;
			}
			if (sumo != 0 && sumo != 1) {
				flag = 1;
			}
			l = r;
		}
		if (flag == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}