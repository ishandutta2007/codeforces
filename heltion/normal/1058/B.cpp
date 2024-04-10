#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, d, m, x, y;
	scanf("%d %d %d", &n, &d, &m);
	for(int i = 0; i < m; i += 1){
		scanf("%d %d", &x, &y);
		if(x + y < d) printf("NO\n");
		else if(x + y > 2 * n - d) printf("NO\n");
		else if(x - y > d) printf("NO\n");
		else if(y - x > d) printf("NO\n");
		else printf("YES\n");
	}
}