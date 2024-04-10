#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,inf=0x3f3f3f3f;
int a[N],fir[N],lst[N],b[N],mx1[N<<2],mx2[N<<2],M,dp[N];
void build(int n){
	memset(mx1,-63,sizeof(mx1)),memset(mx2,-63,sizeof(mx2));
	for(M=1;M<=n+2;M<<=1);
}
void upd(int x,int C){
	mx1[x+M]=C,mx2[x+M]=C-x;
	for(x=(x+M)>>1;x;x>>=1)mx1[x]=std::max(mx1[x<<1],mx1[x<<1|1]),mx2[x]=std::max(mx2[x<<1],mx2[x<<1|1]);
}
int ask(int s,int t,int *mx){
	if(s>t)return -inf;
	int ans=-inf;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=std::max(ans,mx[s^1]);
		if(t&1)ans=std::max(ans,mx[t^1]);
	}
	return ans;
}
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),lst[a[i]]=i;
	for(int i=n;i>=1;--i)fir[a[i]]=i;
	for(int i=1;i<=n;++i)if(fir[i])b[lst[i]]=fir[i];
	build(n);int ans=0;
	for(int i=1;i<=n;++i)if(b[i]){
		dp[i]=std::max({i-b[i]-1,ask(1,b[i]-1,mx1)+i-b[i]-1,ask(b[i],i-1,mx2)+i-1});
		upd(i,dp[i]),ans=std::max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}