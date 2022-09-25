#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,Q,a[N],b[N],mu[N],tmp[N],cntA,cntB;
ll c[N];
ll A[N],B[N],preA[N],sufA[N],preB[N],sufB[N];
ll jb;
void init(int n){
	mu[1]=1;
	for(int i=1;i<=n;++i){
		for(int j=i+i;j<=n;j+=i){
			mu[j]-=mu[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];	
	}
	for(int d=2;d<=n;++d){
		for(int i=d;i<=n;i+=d){
			c[i]+=(b[d]-a[d])*mu[i/d];
		}
	}
	for(int i=1;i<=n;++i){
		if(!mu[i])jb+=llabs(c[i]);
		else if(mu[i]==1)A[++cntA]=c[i];
		else B[++cntB]=c[i];	
	}
	sort(A+1,A+cntA+1);
	sort(B+1,B+cntB+1);
	for(int i=1;i<=cntA;++i){
		preA[i]=preA[i-1]+A[i];	
	}
	for(int i=cntA;i>=1;--i){
		sufA[i]=sufA[i+1]+A[i];
	}
	for(int i=1;i<=cntB;++i){
		preB[i]=preB[i-1]+B[i];	
	}
	for(int i=cntB;i>=1;--i){
		sufB[i]=sufB[i+1]+B[i];
	}
	cin>>Q;
	while(Q--){
		cin>>b[1];
		ll ans=jb,x=b[1]-a[1];
		int pA=lower_bound(A+1,A+cntA+1,-x)-A;
		int pB=lower_bound(B+1,B+cntB+1,x)-B;
		ans+=sufA[pA]+x*(cntA-pA+1)-preA[pA-1]-x*(pA-1);
		ans+=sufB[pB]-x*(cntB-pB+1)-preB[pB-1]+x*(pB-1);
		cout<<ans<<'\n';
	}
	return 0;
}