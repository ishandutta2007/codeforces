#include <stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++){
		int chk[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, l=1;
		for (int x = i; x != 0; x /= 10){
			if (chk[x%10] == 1) l = 0;
			chk[x%10] = 1;
		}
		if (l){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}