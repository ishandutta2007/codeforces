#include <bits/stdc++.h>

using namespace std;

int f[2005];

int main(){
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i=0; i < n; ++i){
		scanf("%d", f+i);
		--f[i];
	}
	sort(f,f+n);
	int ans=0;
	for(int i=n-1; i >= 0; i -= k)
		ans += 2*f[i];
	printf("%d\n", ans);
}