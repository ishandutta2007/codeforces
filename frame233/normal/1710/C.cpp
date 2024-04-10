#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}	
char s[N];int len,dp[N][2][2][2];
int dfs(int dep,int l1,int l2,int l3){
	if(dep==len+1)return 1;
	if(dp[dep][l1][l2][l3]!=-1)return dp[dep][l1][l2][l3];
	int mx1=l1?s[dep]:1,mx2=l2?s[dep]:1,mx3=l3?s[dep]:1,ans=0;
	for(int a=0;a<=mx1;++a)for(int b=0;b<=mx2;++b)for(int c=0;c<=mx3;++c)if((a^b)+(b^c)==(a^c))add(ans,dfs(dep+1,l1&&a==mx1,l2&&b==mx2,l3&&c==mx3));
	return dp[dep][l1][l2][l3]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s",s+1);len=strlen(s+1);for(int i=1;i<=len;++i)s[i]-='0';
	int val=0;for(int i=1;i<=len;++i)val=(2LL*val+s[i])%mod;
	add(val,1);int ans=1LL*val*val%mod*val%mod;
	sub(ans,3LL*dfs(1,1,1,1)%mod),add(ans,3LL*val*val%mod),sub(ans,val);
	printf("%d\n",ans);
	return 0;
}