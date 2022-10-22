#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=0; i < n; ++i){
		int h;
		scanf("%d", &h);
		ans=max(ans, h);
	}
	printf("%d\n", ans);
}