#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2025,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int n,k,a[N],b[N],c[N],ans;
bool check(int len){
	memcpy(b,a,(len+3)<<2);
	for(int i=k;i>=1;--i){
		int sum=0;for(int i=1;i<=len;++i)sum+=b[i];
		if(sum>n)return 0;
		int pos=0;for(int j=len;j>=1;--j)for(int k=0;k<b[j];++k)c[++pos]=j;
		len=pos,memcpy(b,c,(len+3)<<2);
	}
	return 1;
}
void dfs(int dep,int last){
	if(!check(dep-1))return;
	++ans;for(int i=last;i>=1;--i)a[dep]=i,dfs(dep+1,i);
}
int dp[N][N];
int main(){
	read(n,k);
	if(k==1){
		dp[1][1]=1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				add(dp[i+1][j+1],dp[i][j]);
				if(i+j<=n)add(dp[i][i+j],dp[i][j]);
			}
		}
		int ans=0;for(int i=1;i<=n;++i)for(int j=0;j<=n;++j)add(ans,dp[i][j]);
		printf("%d\n",ans);return 0;
	}
	if(k==2){
		dp[0][0]=1;int last=0;
		for(int i=1;i<=n;++i){
			int cost=i*(i+1)/2;if(cost>n)break;else last=i;
			for(int j=0;j<=n;++j){
				for(int k=0;j+k*cost<=n;++k)add(dp[i][j+k*cost],dp[i-1][j]);
			}
		}
		int ans=0;for(int i=1;i<=n;++i)add(ans,dp[last][i]);
		printf("%d\n",ans);return 0;
	}
	dfs(1,n),--ans;
	printf("%d\n",ans);
	return 0;
}