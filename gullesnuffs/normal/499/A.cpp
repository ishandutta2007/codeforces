#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int ans=0;
	int pos=1;
	for(int i=0; i < n; ++i){
		int l, r;
		scanf("%d%d", &l, &r);
		ans += (l-pos)%x;
		ans += r-l+1;
		pos=r+1;
	}
	printf("%d\n", ans);
}