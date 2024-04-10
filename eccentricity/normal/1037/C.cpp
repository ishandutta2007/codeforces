#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL; 
char a[maxn], b[maxn];
int main(){
	int n, ans = 0;
	scanf("%d %s %s", &n, a, b);
	for(int i = 0; i < n; i += 1)
		if(a[i] != b[i]){
			ans += 1;
			if(i + 1 < n && a[i + 1] != b[i + 1] && a[i + 1] != a[i]) i += 1;
		}
	printf("%d", ans);
}