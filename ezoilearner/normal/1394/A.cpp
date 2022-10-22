#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,d,m;
#define Maxn 100010
ll sum[Maxn];
int a[Maxn];

//inline void rd(int &x)

int main(){
    scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}	
	sort(a+1,a+n+1);
	int at=0;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	    if(a[i]<=m)at=i;
	}
	ll Ans=0;
	int n1=at,n2=n-at;
	for(int j=0;j<=n2;++j){
		if(n<1ll*(j-1)*d+j)break;
		int i=n-1ll*(j-1)*d-j;
		i=min(i,n1);
	    if(i>=0)Ans=max(Ans,sum[n]-sum[n-j]+sum[n1]-sum[n1-i]);
	}
	printf("%lld\n",Ans);
	return 0;
}