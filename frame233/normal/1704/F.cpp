#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;
char s[N];int dp[N];
void MAIN(){
	int n;read(n);scanf("%s",s+1);
	int R=std::count(s+1,s+n+1,'R'),B=std::count(s+1,s+n+1,'B');
	if(R!=B)return puts(R>B?"Alice":"Bob"),void();
	int ans=0;
	for(int i=1;i<=n;++i){
		int j=i;while(j<n&&s[j+1]!=s[j])++j;
		ans^=dp[j-i+1],i=j;
	}
	puts(ans?"Alice":"Bob");
}
int mex(const std::vector<int> &vec){
	static bool mark[N];
	for(auto it:vec)mark[it]=1;
	int ans=0;while(mark[ans])++ans;
	for(auto it:vec)mark[it]=0;
	return ans;
}
int main(){
	int n=100;
	for(int i=2;i<=n;++i){
		std::vector<int> vec;
		for(int j=0;j<=i-2;++j)vec.pb(dp[j]^dp[i-j-2]);
		dp[i]=mex(vec);
	}
	for(int i=n+1;i<N;++i)dp[i]=dp[i-34];
	int _;read(_);
	while(_--)MAIN();
	return 0;
}