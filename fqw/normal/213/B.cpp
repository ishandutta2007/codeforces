#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int modnum=1000000000+7;

int f[11][111];
int c[111][111];

int main() {
	int n, a[10];
	cin>>n; for(int i=0; i<10; ++i) cin>>a[i];
	if(n==1) {
		int cnt=0;
		for(int i=0; i<10; ++i) cnt+=a[i];
		if(cnt==0) cout<<10<<endl;
		else if(cnt==1) cout<<1<<endl;
		else cout<<0<<endl;
	} else {
		for(int i=0; i<=100; ++i) c[i][0]=c[i][i]=1;
		for(int i=1; i<=100; ++i) for(int j=1; j<i; ++j) c[i][j]=(c[i-1][j-1]+c[i-1][j])%modnum;
		memset(f, 0, sizeof(f));
		for(int j=0; j<n; ++j)
			f[0][j]=1;
		for(int i=0; i<10; ++i)
			for(int j=0; j<=n; ++j)
				for(int cur=a[i]; j+cur<=n; ++cur) {
					int rest=n-j; if(i==0) --rest;
					f[i+1][j+cur]=((long long)f[i][j]*(long long)c[rest][cur] + f[i+1][j+cur])%modnum;
				}
		int ans=f[10][n];
		//for(int i=0; i<=n; ++i) ans=(ans+f[10][i])%modnum;
		//for(int i=0;i<=n;++i)printf("ans[%d]=%d\n", i, f[10][i]);
		cout<<ans<<endl;
	}
	return 0;
}