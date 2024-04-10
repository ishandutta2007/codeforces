#include<bits/stdc++.h>
using namespace std;
int ans[1500005],n,K,a[1500005];
int Choose(int x,int y){
	if(y==0)return x==0;
	if(x==0)return y==0;
	assert(x>0&&y>0);
	return ((x-1)&(y-1))==(y-1);
}
int main(){
	scanf("%d%d",&n,&K),assert(0<=K&&K<n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),assert(0<a[i]&&a[i]<1048576);
	for(int i=1;i<=n;i++){
		long long x=a[i];
		for(int j=i;j<=i+60&&j<=n;j++){
			if(j>i){
				if(a[j]>22)x=0;
				else x=1ll*x*(1ll<<a[j]);
			}
			if(!x||x>=1048576)break;
			assert(j<=i+50);
			int lef=max(i-2,0)+max(n-j-1,0);
			ans[x]^=Choose(lef,max(K-(i!=1)-(j!=n),0));
		}
	}
	bool fl=0;
	for(int i=1500000;i>=0;i--){
		if(ans[i]||fl||i==0)cout<<ans[i],fl=1;
	}
}