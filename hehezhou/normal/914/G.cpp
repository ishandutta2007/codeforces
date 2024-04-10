#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007,inv2=500000004;
void tag_xor(ll &a,ll &b){
	ll h1=a,h2=b;
	a=(h1+h2)%mod;
	b=(h1-h2+mod)%mod;
}
void tag_ixor(ll &a,ll &b){
	ll h1=a,h2=b;
	a=(h1+h2)*inv2%mod;
	b=(h1-h2+mod)*inv2%mod;
}
void tag_or(ll &a,ll &b){
	b=(a+b)%mod;
}
void tag_ior(ll &a,ll &b){
	b=(b-a+mod)%mod;
}
void tag_and(ll &a,ll &b){
	a=(a+b)%mod;
}
void tag_iand(ll &a,ll &b){
	a=(a-b+mod)%mod;
}
struct node{
	ll a[140000],n;
	node(int _n=17){n=_n;for(int i=0;i<(1<<n);i++)a[i]=0;}
	ll& operator[](int x){
		return a[x];
	}
	const ll& operator[](int x)const{
		return a[x];
	}
	void fwt(void (*f)(ll&,ll&)){
		for(int s=1;s<(1<<n);s<<=1)
			for(int i=0;i<(1<<n);i+=(s<<1))
				for(int j=0;j<s;j++)f(a[i+j],a[i+j+s]);
	}
	node& operator*=(const node &b){
		for(int i=0;i<(1<<n);i++)a[i]=a[i]*b[i]%mod;
		return *this;
	}
	node& operator+=(const node& b){
		for(int i=0;i<(1<<n);i++)a[i]=(a[i]+b[i])%mod;
		return *this;
	}
}buc,f,cntxor,cnt[18],cnts,ans;
int bitsize[140000];
node operator*(node a,const node &b){
	return a*=b;
}
int m,n=17;
ll fb[140010];
int main(){
	for(int i=1;i<(1<<n);i++)bitsize[i]=bitsize[i>>1]+(i&1);
	fb[1]=1;
	for(int i=2;i<(1<<n);i++)fb[i]=(fb[i-1]+fb[i-2])%mod;
	cin>>m;
	for(int i=1,now;i<=m;i++)scanf("%d",&now),buc[now]++,cnt[bitsize[now]][now]++;
	cntxor=buc;
	cntxor.fwt(tag_xor);
	cntxor*=cntxor;
	cntxor.fwt(tag_ixor);
	for(int i=0;i<=n;i++)cnt[i].fwt(tag_or);
	for(int i=0;i<=n;i++){
		f=node(n);
		for(int j=0;j<=i;j++)f+=cnt[j]*cnt[i-j];
		f.fwt(tag_ior);
		for(int j=0;j<(1<<n);j++)
			if(bitsize[j]==i)cnts[j]=f[j];
	}
	for(int i=0;i<(1<<n);i++)cnts[i]=cnts[i]*fb[i]%mod,cntxor[i]=cntxor[i]*fb[i]%mod,buc[i]=buc[i]*fb[i]%mod;
	cnts.fwt(tag_and);
	cntxor.fwt(tag_and);
	buc.fwt(tag_and);
	ans=cnts*cntxor*buc;
	ans.fwt(tag_iand);
	ll lala=0;
	for(int i=0;i<n;i++)lala+=ans[1<<i];
	return cout<<lala%mod,0;
}