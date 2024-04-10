#include <bits/stdc++.h>
#define N 100050
#define k 316
using namespace std;
int n,m,q,a[N],F[N][k+1];
inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	
	for (int i=n;i>=1;i--)
		for (int j=1;j<=k;j++)
			if (i+a[i]+j > n)
				F[i][j] = 1;
			else
				F[i][j] = F[i+a[i]+j][j] + 1;
	
	m = rd();
	while (m--) {
		int p = rd(), d = rd();
		if (d <= k)
			printf("%d\n",F[p][d]);
		else {
			int ans = 0;
			while (p <= n) ans++, p = p + a[p] + d;
			printf("%d\n",ans);
		}
	}
	
	return 0;
}