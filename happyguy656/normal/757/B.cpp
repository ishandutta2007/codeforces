#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

inline int getn(void) {
	char c;while(!isdigit(c=getchar()));
	int res=c^48;
	while(isdigit(c=getchar())) (res*=10)+=c^48;
	return res;
}
const int mxn=1e5+3;int n,m;
int a[mxn],v[mxn],pr[mxn];
void primes(int n) {
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
int cnt[mxn];
void fj(int n) {
	//fenjie
	for(int i=1;pr[i]*pr[i]<=n;++i)if(n%pr[i]==0){
		++cnt[pr[i]];
		while(n%pr[i]==0)n/=pr[i];
	}
	if(n>1)++cnt[n];
}

int main(void) {
	n=getn();
	for(int i=1;i<=n;++i)a[i]=getn();
	primes(400);
	int ans=1;
	for(int i=1;i<=n;++i)fj(a[i]);
	for(int i=1;i<=100000;++i)ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}