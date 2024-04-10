#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define N (1<<20)+50
int n,mask,m;
ll a[N],b[N];
char mp[22][100050];
void fwt(ll *a,int len,int flg) {
	int i,j,k,t;
	for(k=2;k<=len;k<<=1) {
		t=k>>1; for(i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			ll tmp=a[j+t]; a[j+t]=(a[j]-tmp); a[j]+=tmp;
			if(flg==-1) a[j]>>=1,a[j+t]>>=1;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	mask=(1<<n)-1;
	for(i=1;i<=m;i++) {
		int s=0;
		for(j=1;j<=n;j++) s+=((mp[j][i]-'0')<<(j-1));
		a[s]++;
	}
	for(i=0;i<=mask;i++) {
		int cc=0;
		for(j=0;j<n;j++) if(i&(1<<j)) cc++;
		b[i]=max(cc,n-cc);
	}
	fwt(a,mask+1,1),fwt(b,mask+1,1);
	for(i=0;i<=mask;i++) a[i]=a[i]*b[i];
	fwt(a,mask+1,-1);
	ll ans=0;
	for(i=0;i<=mask;i++) ans=max(ans,a[i]);
	
	printf("%lld\n",n*m-ans);

	return 0;
}