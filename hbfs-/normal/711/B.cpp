#include <iostream>
#include <cstdio>
#define N 550

using namespace std;

typedef long long LL;

int n,x,y;
LL sum,ans,a[N][N];

int main()
{
	bool flag = true;
	scanf("%d",&n);

	if (n == 1) { printf("1\n"); return 0; }

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			scanf("%I64d",&a[i][j]);
			if (a[i][j] == 0) x = i , y = j; 
		}
		
	for (int i=1;i<=n;i++) 
		if (x == 1)
			sum += a[2][i];
		else
			sum += a[1][i];
	

	
	LL p = 0;
	for (int i=1;i<=n;i++) p += a[x][i];
	LL ans = sum - p;
	if (ans < 1) flag = false;
	
	a[x][y] = ans;
	
	
	for (int j=1;j<=n;j++) {
		LL tot = 0;
		for (int i=1;i<=n;i++) tot += a[j][i];
		if (tot != sum) flag = false;
	}
		
	
	for (int j=1;j<=n;j++) {
		LL tot = 0;
		for (int i=1;i<=n;i++) tot += a[i][j];
		if (tot != sum) flag = false;
	}
	
	
	LL tot = 0;
	for (int i=1;i<=n;i++) tot += a[i][i];
	if (tot != sum) flag = false;
	
	tot = 0;
	for (int i=1;i<=n;i++) tot += a[i][n-i+1];
	if (tot != sum) flag = false;
	
	if (!flag) puts("-1"); else cout << ans << endl;
	
	return 0;
}