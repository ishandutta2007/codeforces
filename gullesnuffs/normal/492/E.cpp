#include <bits/stdc++.h>

using namespace std;

long long n, m, dx, dy;
int x[1000005];
int ans[1000005];

int main(){
	cin >> n >> m >> dx >> dy;
	for(long long i=0; i < n; ++i){
		x[(dy*i)%n]=(dx*i)%n;
	}
	for(int i=0; i < m; ++i){
		int X, Y;
		scanf("%d%d", &X, &Y);
		X=(X-x[Y]+n)%n;
		++ans[X];
	}
	int best=0;
	int bestX=0;
	for(int i=0; i < n; ++i){
		if(ans[i] > best){
			best=ans[i];
			bestX=i;
		}
	}
	printf("%d %d\n", bestX, 0);
	
}