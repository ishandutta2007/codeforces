#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int a; scanf("%d", &a);
		int pos = 0;
		for (int i = 0; i < 30; i++){
			if ((1 << i) - 1 >= a){
				pos = (1 << i) - 1;
				break;
			}
		}
		if (pos == a){
			int res = -1, ans = pos;
			for (int i = 2; i * i <= pos; i++){
				if (pos % i == 0){
					res = i;
					break;
				}
			}
			if (res == -1) res = pos;
			printf("%d\n", ans / res);
		} else printf("%d\n", pos);
	}
	return 0;
}