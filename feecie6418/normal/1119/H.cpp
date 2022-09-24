#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,inv4=748683265;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,K,X,Y,Z,s1[140005],s2[140005],s3[140005],ans[140005],t=0;
void Xor(int a[],int flag){
	for(int i=1;i<(1<<K);i<<=1){
		for(int j=i;j<(1<<K);j++){
			int x=a[i^j],y=a[j];
			if(i&j)a[i^j]=(x+y)%mod,a[j]=(x-y+mod)%mod;
		}
	}
	if(flag==-1){
		for(int i=0;i<(1<<K);i++)a[i]=1ll*Power(1<<K,mod-2)*a[i]%mod;
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&K,&X,&Y,&Z);
	for(int i=1,x,y,z;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		y^=x,z^=x,t^=x,s1[y]++,s2[z]++,s3[y^z]++;
	}
	Xor(s1,1),Xor(s2,1),Xor(s3,1);
	for(int i=0;i<(1<<K);i++){
		int x=(0ll+s1[i]+s2[i]+s3[i]+n)%mod*inv4%mod;
		int y=1ll*(s1[i]+n)*(mod+1)/2%mod-x;
		int z=1ll*(s2[i]+n)*(mod+1)/2%mod-x;
		int w=1ll*(s3[i]+n)*(mod+1)/2%mod-x;
		int prod=1;
		prod=1ll*prod*Power((0ll+X+Y+Z)%mod,x)%mod;
		prod=1ll*prod*Power((0ll+X+Y-Z+mod)%mod,y)%mod;
		prod=1ll*prod*Power((0ll+X-Y+Z+mod)%mod,z)%mod;
		prod=1ll*prod*Power((0ll+X-Y-Z+2*mod)%mod,w)%mod;
		ans[i]=prod;
	}
	Xor(ans,-1);
	for(int i=0;i<(1<<K);i++)printf("%d ",ans[i^t]);
}