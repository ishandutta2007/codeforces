#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long a[N];
int b[N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	long long fi=0,se=0;
	for(int S=1;S<=2*m;S++) {
		b[1]=0;
		b[n+2]=S-1;
		for(int i=1;i<=n;i++)
			b[i+1]=a[i]%S;
		sort(b+1,b+n+3);
		for(int i=n+2,f=0;i>1;i--,f^=1) {
			int l=b[i-1]+1,r=min(m,b[i]);
			if(f==0)l=max(l,b[n+1]/2+1);
			else l=max(l,b[n]/2+1);
			int L=max(l,S-r),R=min(r,S-l);
			if(L>R)continue;
			if(f==0)se+=R-L+1;
			else fi+=R-L+1;
		}
	}
	long long A=1ll*m*m-fi-se;
	printf("%lld %lld %lld %lld\n",A/2,A/2,fi,se);
	return 0;
}