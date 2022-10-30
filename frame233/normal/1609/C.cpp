#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,M=1000005;
int a[N],fir[N],sec[N];
bool pr[M];int p[M],pos;
void sieve(){
	for(int i=2;i<M;++i){
		if(!pr[i])p[++pos]=i;
		for(int j=1;j<=pos&&i*p[j]<M;++j){
			pr[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
void MAIN(){
	int n,e;read(n,e);
	for(int i=1;i<=n;++i){
		read(a[i]);
		if(a[i]!=1){
			if(pr[a[i]])a[i]=0;
		}
	}
	std::fill(fir+1,fir+n+2,n+1),std::fill(sec+1,sec+n+2,n+1);
	long long ans=0;
	for(int i=n;i>=1;--i){
		if(a[i]!=1)fir[i]=i,sec[i]=i+e>n?n+1:fir[i+e];
		else fir[i]=i+e>n?n+1:fir[i+e],sec[i]=i+e>n?n+1:sec[i+e];
		if(i+e<=n&&fir[i]<=n){
			if(a[fir[i]]==0)continue;
			int L=fir[i]==i?0:(fir[i]-1-i)/e,R=(sec[i]-1-i)/e;
			ans+=R-L;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	sieve();
	int _;read(_);
	while(_--)MAIN();
	return 0;
}