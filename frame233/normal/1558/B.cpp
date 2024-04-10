#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=4000005;
int dp[N],mod,s[N];
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main(){
	int n;read(n,mod);
	dp[n]=1,s[n]=1;
	for(int i=n-1;i>=1;--i){
		dp[i]=2*s[i+1]%mod;
		for(int l=i+i;l<=n;l+=i)add(dp[i],s[l]);
		for(int l=i+1;l<=n;l+=i+1)sub(dp[i],s[l]);
		s[i]=s[i+1],add(s[i],dp[i]);
	}
	printf("%d\n",dp[1]);
	return 0;
}