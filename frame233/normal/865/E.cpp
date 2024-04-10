#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
typedef long long ll;const ll INF=1e18;
char _s[15];int s[15],v[15],n,sum[1<<13];ll f[1<<13];
ll solve(){
	if(v[n-1]>=16)return INF;
	sum[0]=0;for(int i=0;i<n-1;++i)sum[1<<i]=v[i];
	for(int st=1;st<1<<(n-1);++st)sum[st]=sum[st&(-st)]+sum[st&(st-1)];
	for(int st=0;st<1<<(n-1);++st)sum[st]+=v[n-1];
	memset(f,63,sizeof(f)),f[0]=0;
	for(int st=0;st<1<<(n-1);++st)if(f[st]<INF){
		for(int i=0;i<n-1;++i)if(!(st>>i&1)&&sum[st|1<<i]>=0&&sum[st|1<<i]<16){
			chmin(f[st|1<<i],f[st]|((ll)sum[st]<<(i*4)));
		}
	}
	return f[(1<<(n-1))-1];
}
int main(){
	scanf("%s",_s),n=strlen(_s),std::reverse(_s,_s+n);
	for(int i=0;i<n;++i)s[i]=isdigit(_s[i])?_s[i]-'0':_s[i]-'a'+10;
	int sum=0;for(int i=0;i<n;++i)sum+=s[i];
	if(sum%15)return puts("NO"),0;
	sum/=15;ll ans=1e18;
	for(int st=0;st<1<<(n-1);++st)if(__builtin_popcount(st)==sum){
		for(int i=0;i<n;++i)v[i]=s[i];
		for(int i=0;i<n-1;++i)if(st>>i&1)v[i]-=16,++v[i+1];
		ans=std::min(ans,solve());
	}
	if(ans>=INF)return puts("NO"),0;
	for(int i=n-1;i>=0;--i){
		int tmp=ans>>(i*4)&15;
		printf("%c",tmp<10?tmp+'0':tmp-10+'a');
	}
	printf("\n");
	return 0;
}