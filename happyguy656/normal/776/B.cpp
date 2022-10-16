#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>

int n;const int mxn=1e6+3;
int m;
int v[mxn],pr[mxn];
void primes(void) {
	//memset v[i]=0
	m=0;
	for(int i=2;i<=n;++i) {
		if(!v[i])v[i]=i,pr[++m]=i;
		
		for(int j=1;j<=m;++j) {
			if(pr[j]>v[i] || pr[j]>n/i)break;
			v[i*pr[j]]=pr[j];
		}
	}
}
int main(void) {
	scanf("%d",&n);++n;if(n<4)puts("1");else puts("2");
	primes();
	for(int i=2;i<=n;++i)if(v[i]==i)printf("1 ");else printf("2 ");
	puts("");
	return 0;
}