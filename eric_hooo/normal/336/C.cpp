#include <bits/stdc++.h>
using namespace std;
 
int a[100010];
 
int main(){
	int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
    	scanf("%d", &a[i]);
	}
    for (int i = 29; i >= 0; i--){
        int tmp = (1 << (i + 1)) - 1;
        int cnt = 0;
        for (int j = 1; j <= n; j++){
        	if (a[j] & (1 << i)) cnt++, tmp &= a[j];
		}
        if (tmp % (1 << i) == 0){
            printf("%d\n", cnt);
            for (int j = 1; j <= n; j++){
            	if (a[j] & (1 << i)) printf("%d ", a[j]);
			}
			printf("\n");
            return 0;
        }
    }
    return 0;
}