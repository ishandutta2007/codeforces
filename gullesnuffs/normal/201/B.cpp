#include <stdio.h>
#include <math.h>

using namespace std;

long long c[1005][1005];
int m, n, pos[2];
double phi=(sqrt(5.0)+1)/2.0;
double resphi=1/(phi*phi);

long long disSum(bool y, int p){
	long long ans=0;
	if(y){
		for(int i=0; i < n; ++i)
			for(int j=0; j < m; ++j)
				ans += c[i][j]*(2+4*j-4*p)*(2+4*j-4*p);
	}
	else{
		for(int i=0; i < n; ++i)
			for(int j=0; j < m; ++j)
				ans += c[i][j]*(2+4*i-4*p)*(2+4*i-4*p);
	}
	return ans;
}

long long goldenSection(bool y, int x1, int x2, int x3, long long prev){
	if(x3-x1 <= 2){
		pos[y]=x2;
		return prev;
	}
	int x4;
	if(x3-x2 > x2-x1)
		x4=x2+(int)((x3-x2)*resphi)+1;
	else
		x4=x2-(int)((x2-x1)*resphi)-1;
	long long p=disSum(y, x4);
	if(p > prev || (p == prev && x4 > x2)){
		if(x3-x2 > x2-x1)return goldenSection(y, x1, x2, x4, prev);
		return goldenSection(y, x4, x2, x3, prev);
	}
	if(x3-x2 > x2-x1)return goldenSection(y, x2, x4, x3, p);
	return goldenSection(y, x1, x4, x2, p);
}

int main()
{
	long long ans=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			scanf("%d", c[i]+j);
	for(int i=0; i < 2; ++i){
		int t=(i == 1)?m:n;
		ans += goldenSection(i, -1, int(t*resphi), t, disSum(i, int(t*resphi)));
	}
	if(ans == 0)
		printf("0\n0 0");
	else
		printf("%I64d\n%d %d", ans, pos[0], pos[1]);
	return 0;
}