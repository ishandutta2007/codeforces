#include<bits/stdc++.h>
using namespace std;
const int B1=233,B2=127;
int mod1,mod2,pw1[300005]={1},pw2[300005]={1},n;
char a[300005];
typedef pair<int,int> pr;
typedef long long ll;
struct Hash{
	int x1,x2,len;
};
vector<Hash> f[1200005];
Hash operator +(Hash x1,Hash x2){
	return {(1ll*x1.x1*pw1[x2.len]+x2.x1)%mod1,(1ll*x1.x2*pw2[x2.len]+x2.x2)%mod2,x1.len+x2.len};
}
bool operator ==(Hash x1,Hash x2){
	return x1.x1==x2.x1&&x1.x2==x2.x2;
}
void Build(int p,int l,int r,int all){
	f[p].resize(r-l+1);
	if(l==r){
		f[p][0]={(int)a[l],(int)a[l],1};
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid,all>>1);
	Build(p*2+1,mid+1,r,all>>1);
	for(int i=0;i<r-l+1;i++){
		if(i&all){
			f[p][i]=f[p*2+1][i^all]+f[p*2][i^all];
		}
		else {
			f[p][i]=f[p*2][i]+f[p*2+1][i];
		}
	}
}
bool Bigger(int x,int y){
	int p=1,q=1,all=(1<<n-1),lcp=0;
	for(int i=n-1;i>=0;i--){
		int xx=p*2+((x>>i)&1);
		int yy=q*2+((y>>i)&1);
		if(f[xx][x&(all-1)]==f[yy][y&(all-1)]){
			lcp+=all;
			p=p*2+!((x>>i)&1);
			q=q*2+!((y>>i)&1);
		}
		else {
			p=xx;
			q=yy;
		}
		all>>=1;
	}
	if(a[lcp^x]>a[lcp^y])return 1;
	return 0;
}
int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()+time(0)+clock());
	while(1){
		mod1=rng()%50000000+1000000000;
		bool fl=0;
		for(int i=2;i*i<=mod1;i++){
			if(mod1%i==0)fl=1;
		}
		if(!fl)break;
	}
	while(1){
		mod2=rng()%50000000+1000000000;
		bool fl=0;
		for(int i=2;i*i<=mod2;i++){
			if(mod2%i==0)fl=1;
		}
		if(!fl)break;
	}
	scanf("%d%s",&n,a);
	for(int i=1;i<(1<<n);i++)pw1[i]=1ll*pw1[i-1]*B1%mod1,pw2[i]=1ll*pw2[i-1]*B2%mod2;
	Build(1,0,(1<<n)-1,(1<<n-1));
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		if(Bigger(ans,i)){
			ans=i;
		}
	}
	for(int i=0;i<(1<<n);i++)cout<<a[i^ans];
}