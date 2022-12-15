#include <bits/stdc++.h>
using namespace std;
 
const int mxN=3e3, mxS=mxN*(mxN+1)/2+1, M=1e9+7;
int n, a[mxN], c[mxS][2], p[mxS], dp[mxS], ans, m=1;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	dp[0]=1;
	p[0]=-1;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=i, u=0; ~j; u=c[u][a[j--]]) {
			if(c[u][a[j]])
				continue;
			for(int k=0, v=u, b=0; k<4&&~v; ++k, v=p[v]) {
				b=b<<1|a[j+k];
				if(k<3||b^3&&b^5&&b<14)
					dp[m]=(dp[m]+dp[v])%M;
			}
			ans=(ans+dp[m])%M;
			p[m]=u;
			c[u][a[j]]=m++;
		}
		cout << ans << "\n";
	}
}