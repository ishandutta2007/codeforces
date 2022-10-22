#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=0; i < n; ++i){
		int p,q;
		scanf("%d%d", &p, &q);
		if(p <= q-2)
			++ans;
	}
	printf("%d\n", ans);
}