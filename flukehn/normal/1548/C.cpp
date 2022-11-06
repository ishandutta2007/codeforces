#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int Pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
const int N=3e6+11;
int jc[N],jcv[N];
int C(int a,int b){
	if(b<0||a<b)return 0;
	return 1LL*jc[a]*jcv[b]%mo*jcv[a-b]%mo;
}
int ans[N][3];
int n;
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	jc[0]=1;
	for(int i=1;i<N;++i)jc[i]=1LL*jc[i-1]*i%mo;
	jcv[N-1]=Pow(jc[N-1],mo-2);
	for(int i=N-1;i>=1;--i)jcv[i-1]=1LL*jcv[i]*i%mo;
	cin>>n;
	for(int i=1;i<=2;++i){
		for(int k=0;k<=2;++k)
			for(int j=1;j<=n;++j)	
				ans[i][k]=(ans[i][k]+C(3*j-k,i))%mo;
	}
	const int v3=Pow(3,mo-2);
	for(int x=3;x<=3*n;++x){
		int t=(C(3*n,x+1)+C(3*n,x))%mo;
		ans[x][2]=(3LL*mo+t-2*ans[x-1][2]-ans[x-1][1])%mo*v3%mo;//(ans[x-1][0]+ans[x][0])-C(3*n,x)-C(3*n,x-1);
		ans[x][1]=(ans[x-1][2]+ans[x][2])%mo;
		ans[x][0]=(ans[x-1][1]+ans[x][1])%mo;
	}
	int Q;
	cin>>Q;
	while(Q--){
		int x;
		cin>>x;
		cout<<ans[x][0]<<"\n";
	}
}