#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int k;
		scanf("%d", &k);
		int tot = 0;
		for (int i = 0; i < 7; i++){
			scanf("%d", &a[i]);
			tot += a[i];
		}
		int res = k / tot * 7;
		int last = k % tot;
		if (last == 0) last = tot, res -= 7;
		int minj = 0x3f3f3f3f;
		for (int i = 0; i < 7; i++){
			int now = 0, sum = 0;
			while (now < last){
				now += a[(i + sum) % 7], sum++;
			}
			minj = min(minj, sum);
		}
		printf("%d\n", res + minj);
	}
	return 0;
}