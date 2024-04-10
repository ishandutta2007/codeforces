#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
char _s[20];int a[20],b[20],*arr;ll dp[16][16][1<<16];
int get(int *a){
	scanf("%s",_s);int n=strlen(_s);
	for(int i=0;i<n;++i)a[i]=isdigit(_s[i])?_s[i]-'0':_s[i]-'a'+10;
	std::reverse(a,a+n);return n;
}
bool check(int *b,int lb){
	int st=0,v=0;
	for(int i=0;i<lb;++i)st|=1<<b[i];
	for(int i=0;i<4&&i<lb;++i)v|=b[i]<<(i*4);
	return (v^st)<v;
}
ll dfs(int dep,int mx,int v,bool flag){
	if(dep==-1)return v>>mx&1;
	if(!flag&&dp[dep][mx][v]!=-1)return dp[dep][mx][v];
	int lim=flag?arr[dep]:15;ll ans=0;
	for(int i=0;i<=lim;++i)ans+=dfs(dep-1,std::max(mx,i),dep<4?(v|(i<<(dep*4))):v,flag&&(i==lim));
	if(!flag)dp[dep][mx][v]=ans;
	return ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int q;read(q);
	while(q--){
		int la=get(a),lb=get(b);
		arr=b;ll ans=dfs(lb-1,0,0,1)+check(a,la);
		arr=a,ans-=dfs(la-1,0,0,1);printf("%lld\n",ans);
	}
	return 0;
}