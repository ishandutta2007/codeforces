#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, s;
	scanf("%d%d", &n, &s);
	int ans=-1;
	for(int i=0; i < n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		if(100*x+y <= 100*s){
			int newAns;
			if(y == 0)
				newAns=0;
			else
				newAns=100-y;
			ans=max(ans, newAns);
		}
	}
	printf("%d\n", ans);
}