#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int Pow(int a,long long b){
	int r=1;
	for(;b;b>>=1,a=1ll*a*a%mo)
		if(b&1)r=1ll*r*a%mo;
	return r;
}
int p4[66];
int k;
long long n;
const int N=2011;
int m;
map<long long, int> F;
set<long long> S;
struct P{
	int f[6],sum;
	P(){
		memset(f,0,sizeof f);
		sum=0;
	}	
};
P dp(long long x,int dep=1){
	if(!S.count(x)){
		int w=p4[k-dep+1],t=6LL*w%mo;
		P ret;
		for(int i=0;i<6;++i)ret.f[i]=w;
		ret.sum=t;
		return ret;
	}
	if(dep==k) {
		P t;
		t.sum=t.f[F[x]]=1;
		return t;
	}
	P l=dp(x*2,dep+1);
	P r=dp(x*2+1,dep+1);
	/*if(x==2){
		for(int i=0;i<6;++i)cout<<l.f[i]<<" \n"[i==5];
		for(int i=0;i<6;++i)cout<<r.f[i]<<" \n"[i==5];
	}*/
	int f[6]={0},sum=0;
	for(int i=0;i<6;++i){
		f[i]=1LL*(1LL*l.sum-l.f[i]-l.f[i^1])*(1LL*r.sum-r.f[i]-r.f[i^1])%mo;
		if(f[i]<0)f[i]+=mo;
		sum=(sum+f[i])%mo;
	}
	if(F.count(x)) {
		//cerr<<"F "<<x<<endl;
		int t=F[x];
		for(int i=0;i<6;++i)f[i]=(i==t?f[i]:0);
		sum=f[t];
	}
	P ret;
	for(int i=0;i<6;++i)ret.f[i]=f[i];
	ret.sum=sum;
	//if(x==1) {
		//cout<<x<<" "<<sum<<" : ";
		//for(int i=0;i<6;++i)cout<<f[i]<<" \n"[i==5];
	//}
	return ret;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<62;++i)p4[i]=Pow(4,(1LL<<i)-2);
	while(cin>>k){
		F.clear();
		n=(1LL<<k)-1;
		cin>>m;
		for(int i=1;i<=m;++i){
			string s;
			long long a;
			cin>>a>>s;
			long long x=a;
			int p[64], t=0;
			while(x)p[t++]=x%2,x/=2;
			reverse(p,p+t);
			for(int i=0;i<t;++i){
				x=x*2+p[i];
				S.insert(x);
			}

			const char w[]="wygbro";
			// w,y g,b r,o
			int j;
			for(j=0;s[0]!=w[j];++j);
			F[a]=j;
		}
		cout<<dp(1).sum<<"\n";
	}
}