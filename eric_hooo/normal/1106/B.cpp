#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[100010], c[100010];
int T[100010], cnt[100010];
int pos[100010];
pii now;
int o = 0;

vector <int> all[1000010];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		pos[i] = all[c[i]].size();
		all[c[i]].push_back(a[i]);
	}
	for (int i = 0; i < m; i++){
		int t, d;
		scanf("%d%d", &t, &d);
		if (all[c[t]][pos[t]] >= d){
//			cout << "     case1" << endl;
			all[c[t]][pos[t]] -= d;
			printf("%I64d\n", 1ll * c[t] * d);
		} else {
			long long ans = 1ll * all[c[t]][pos[t]] * c[t];
			d -= all[c[t]][pos[t]];
			all[c[t]][pos[t]] = 0;
			long long sum = 0, cost = 0;
			int tmp = now.fi;
			for (int &i = now.fi; i <= 1000005; i++){
				o = 0;
				for (int &j = (i == tmp ? now.se : o); j < all[i].size(); j++){
					sum += all[i][j];
					ans += 1ll * all[i][j] * i;
					now.se = j;
					if (sum > d){
						sum -= all[i][j];
						ans -= 1ll * all[i][j] * i;
						goto OUT;
					}
					all[i][j] = 0;
				}
			}
			OUT:;
			if (sum == d){
				printf("%I64d\n", ans);
				continue;
			}
			if (now.fi == 1000006){
				printf("0\n");
				continue;
			}
			d -= sum;
			all[now.fi][now.se] -= d;
			ans += 1ll * now.fi * d + cost;
			printf("%I64d\n", ans);
			continue;
		}
	}
	return 0;
}