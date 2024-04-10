#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=205;int n,k;typedef long long ll;
int x[N],y[N],dp[N][N];ll a[N][N],all;
inline int nxt(int x){return x+1==n?0:x+1;}
inline int pre(int x){return !x?n-1:x-1;}
inline ll cross(ll x1,ll y1,ll x2,ll y2){return x1*y2-x2*y1;}
bool check(ll mid){
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)dp[i][j]=0;
	for(int len=3;len<=n;++len){
		int i=0,j=len-1;
		do{
			if(a[i][j]<mid){i=nxt(i),j=nxt(j);continue;}
			dp[i][j]=1;
			for(int k=nxt(i),p=i;k!=j;k=nxt(k)){
				while(a[k][p]-a[j][i]<mid)p=nxt(p);
				chmax(dp[i][j],dp[p][k]+1);
			}
			for(int k=nxt(i),p=k;k!=j;k=nxt(k)){
				while(p<j&&a[p][k]-a[j][i]-a[p][j]-a[i][k]<mid)p=nxt(p);
				if(a[p][k]-a[j][i]-a[p][j]-a[i][k]<mid)break;
				chmax(dp[i][j],dp[p][j]+dp[i][k]+1);
			}
			i=nxt(i),j=nxt(j);
		}while(i);
	}
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(dp[i][j]+dp[j][i]>=k+1)return true;
	return false;
}
int main(){
	read(n,k);
	for(int i=0;i<n;++i)read(x[i],y[i]);
	for(int i=0;i<n;++i){
		int j=nxt(i),k;ll s=0;
		for(;j!=i;j=k)a[i][j]=s,k=nxt(j),s+=cross(x[j]-x[i],y[j]-y[i],x[k]-x[i],y[k]-y[i]);
	}
	all=a[0][n-1];for(int i=0;i<n;++i)a[i][i]=all;
	ll l=0,r=1e18,mid;while(l<r)mid=(l+r+1)>>1,check(mid)?l=mid:r=mid-1;
	printf("%lld\n",l);
	return 0;
}