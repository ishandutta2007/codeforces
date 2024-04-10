#include <bits/stdc++.h>
using namespace std;
int main(){
	int q; cin >> q;
	while (q--){
		long long a, b, m;
		cin >> a >> b >> m;
		if (a == b){
			printf("1 %I64d\n", a);
			continue;
		}
		for (int i = 2; i <= 50; i++){
//			cout << "i:" << i << " " << (a + 1ll) * (1ll << i - 2) << " " << (a + m) * (1ll << i - 2) << endl;
			if (b / (a + 1ll) < (1ll << i - 2)) break; // down
			if (b / (a + m) > (1ll << i - 2)) continue; // up
			long long pw = (1ll << i - 2);
//			cout << "  pw:" << pw << endl;
			long long bb = b - (1ll << i - 2) * (a + 1ll);
//			cout << "  bb:" << bb << endl;
			long long k = (bb - bb % pw) / pw + 1ll;
//			cout << "  k:" << k << endl;
			if (k > m || (k == m && bb % pw != 0)) continue;
			long long tmp = bb % pw;
//			cout << "  tmp:" << tmp << endl;
			long long ans = a;
			long long sum = a;
			printf("%d ", i);
			printf("%I64d ", ans);
			for (int j = 2; j <= i; j++){
				long long r = k + (i - j - 1ll < 0 ? 0 : ((tmp >> i - j - 1ll) & 1ll));
				ans = sum + r, sum += ans;
				printf("%I64d ", ans);
				if (j == 3) continue;
			}
			printf("\n");
			goto END;
		}
		printf("-1\n");
		END:;
	}
	return 0;
}