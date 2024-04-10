#include<cstdio>
#include<cstring>
#include<algorithm>
#define mymin(x,y) ((x)<(y)?(x):(y))
#define mymax(x,y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long ll;
const int N=1e5+100,o=320;
bool bk[N];
ll a[N],b[N],p[N],g[N];int d[340][340],h[N],L[N],R[N];
bool cmp(int n1,int n2) {return (a[n1]>a[n2]);}
int ju(int n1,int n2){
	if(b[n2]==b[n1]) return 0;
	else return 1e9;
	return ((b[n2]-b[n1])*1.0/(a[n1]-a[n2]));
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),h[i]=i;
	for(int i=1;i<=n;i+=o){
		int t=mymin(i+o-1,n);
		sort(h+i,h+t+1,cmp);
		d[(i-1)/o][1]=h[i];
		L[(i-1)/o]=R[(i-1)/o]=1;
	}
	for(int i=0;i<=(n-1)/o;i++) g[i]=1;
	ll Ans=0;
	memset(bk,true,sizeof(bk));
	for(int i=1;i<=n;i++){
		ll Max=0;int Max1=0;
		for(int j=0;j<=(n-1)/o;j++)
			if(L[j]<=R[j]&&Max<b[d[j][L[j]]]+p[j]+a[d[j][L[j]]]*g[j])
				Max=b[d[j][L[j]]]+a[d[j][L[j]]]*g[j]+p[j],Max1=j;
		if(Max==0) break;
		Ans+=Max;
		for(int j=0;j<Max1;j++) p[j]+=a[d[Max1][L[Max1]]];
		for(int j=Max1+1;j<=(n-1)/o;j++){
			g[j]++;
			while(L[j]<R[j]){
				ll t1=b[d[j][L[j]]]+a[d[j][L[j]]]*g[j];
				ll t2=b[d[j][L[j]+1]]+a[d[j][L[j]+1]]*g[j];
				if(t1<=t2) L[j]++;
				else break;
			}
		}
		bk[d[Max1][L[Max1]]]=false;
		int t=mymin(Max1*o+o,n);
		for(int j=t;j>=Max1*o+1;j--){
			if(bk[j]){
				if(j<d[Max1][L[Max1]]) b[j]=b[j]+a[j]*g[Max1]+p[Max1]+a[d[Max1][L[Max1]]];
				else b[j]=b[j]+a[j]*(g[Max1]+1)+p[Max1];
			}
		}
		g[Max1]=p[Max1]=0;
		L[Max1]=1;R[Max1]=0;
		for(int j=t;j>=Max1*o+1;j--){
			if(bk[j]){
				while(L[Max1]<=R[Max1]&&b[d[Max1][R[Max1]]]<=b[j]) R[Max1]--;
				while(L[Max1]<R[Max1]&&ju(d[Max1][R[Max1]-1],d[Max1][R[Max1]])>=ju(d[Max1][R[Max1]],j)) R[Max1]--;
				d[Max1][++R[Max1]]=j;
			}
		}
	}
	printf("%lld\n",Ans);
	return 0;
}