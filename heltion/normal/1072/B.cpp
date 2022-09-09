#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
int n, a[maxn], b[maxn], t[maxn];
bool test(){
	for(int i = 2; i <= n; i += 1){
		bool flag = false;
		for(t[i] = 0; t[i] <= 3; t[i] += 1)
			if((t[i] | t[i - 1]) == a[i - 1] && (t[i] & t[i - 1]) == b[i - 1]){
				flag = true;
				break;
			}
		if(flag == false) return false;
	}
	printf("YES\n");
	for(int i = 1; i <= n; i += 1) printf("%d ", t[i]);
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i += 1) scanf("%d", a + i);
	for(int i = 1; i < n; i += 1) scanf("%d", b + i);
	for(t[1] = 0; t[1] <= 3; t[1] += 1) if(test()) return 0;
	printf("NO");
}