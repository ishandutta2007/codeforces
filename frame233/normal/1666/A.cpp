#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=20005,mod1=1000000007,mod2=1000000009,S=100;typedef long long ll;typedef unsigned long long ull;
ll ksm(ll a,ll b,ll mod){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
struct hash{
	ll a,b;
	inline hash(){a=b=0;}
	inline hash(ll x){a=x,b=x;}
	inline hash(ll x,ll y){a=x,b=y;}
	inline hash operator += (const hash &o){a=a+o.a>=mod1?a+o.a-mod1:a+o.a,b=b+o.b>=mod2?b+o.b-mod2:b+o.b;return *this;}
	inline hash operator + (const hash &o)const{hash x(*this);return x+=o;}
	inline hash operator -= (const hash &o){a=a-o.a<0?a-o.a+mod1:a-o.a,b=b-o.b<0?b-o.b+mod2:b-o.b;return *this;}
	inline hash operator - (const hash &o)const{hash x(*this);return x-=o;}
	inline hash operator * (const hash &o)const{return hash(a*o.a%mod1,b*o.b%mod2);}
	inline bool operator == (const hash &o)const{return a==o.a&&b==o.b;}
	inline bool operator < (const hash &o)const{return a==o.a?b<o.b:a<o.a;}
}base=hash(23333),ibase=hash(ksm(23333,mod1-2,mod1),ksm(23333,mod2-2,mod2));
char s[N];int m[N];hash s1[N],s2[N],s3[N],pw[N],ipw[N],v[N];
int preD[N];std::vector<int> Q[N];bool is[N];
std::unordered_map<ull,int> mp[S+5];
int nl[N],nrl[N];
int main(){
	pw[0]=hash(1);for(int i=1;i<N;++i)pw[i]=pw[i-1]*base;
	ipw[0]=hash(1);for(int i=1;i<N;++i)ipw[i]=ipw[i-1]*ibase;
	scanf("%s",s+1);int n=strlen(s+1),lu=n+1,ans=0;
	nrl[n+1]=n+1,nl[n+1]=n+1;
	for(int i=n;i>=1;--i){
		nrl[i]=s[i]=='R'&&s[i+1]=='L'?nrl[i+2]:i;
		nl[i]=s[i+1]=='L'?nl[i+1]:i;
	}
	for(int i=n;i>=1;--i){
		if(s[i]=='U')lu=i;
		int j=nrl[i];ans+=(j-i)/2;int jj=j;if(lu>n)continue;
		if(s[j]=='L'||s[j]=='U')continue;
		j=nl[j],m[i]=lu-j;if(m[i]&&m[i]%2==0)ans-=(jj-i)/m[i];
	}
	for(int i=1;i<=n;++i){
		s1[i]=s1[i-1],s2[i]=s2[i-1],s3[i]=s3[i-1];
		if(s[i-1]!='R'&&s[i+1]!='L')s1[i]+=pw[i];
		if(s[i]=='U')s2[i]+=pw[i];
		if(s[i]=='D')s3[i]+=pw[i];
		preD[i]=preD[i-1]+(s[i]=='D');
	}
	for(int i=1;i<=n;++i){
		if(m[i]<=0)continue;
		if(s[i]=='L'||s[i+m[i]-1]=='R')continue;
		if(m[i]>=S){
			for(int j=i+m[i];j<=n+1;j+=m[i]){
				if(s[j-m[i]]=='L'||s[j-1]=='R')break;
				if(preD[j-1]-preD[j-m[i]-1]==0){
					hash A=s1[j-2]-s1[i],B=(s2[j-1]-s2[i-1])*ipw[m[i]]+(s3[j-1]-s3[i-1])*pw[m[i]];
					if(s[i+1]!='L')A+=pw[i];
					if(s[j-2]!='R')A+=pw[j-1];
					if(A==B)++ans;
				}
			}
		}
		else Q[m[i]].push_back(i);
	}
	for(int M=1;M<S;++M){
		for(int i=0;i<M;++i)mp[i].clear();
		for(auto it:Q[M])is[it]=1;
		for(int i=n+1;i>=1;--i){
			if(is[i]){
				hash A=(s1[i]-s2[i-1]*ipw[M]-s3[i-1]*pw[M]);
				if(s[i+1]!='L')A-=pw[i];
				ans+=mp[i%M][((ull)A.a<<32)|A.b];
			}
			if(preD[i-1]-preD[i-M-1]==0){
				hash A=s1[i-2]-s2[i-1]*ipw[M]-s3[i-1]*pw[M];
				if(s[i-2]!='R')A+=pw[i-1];
				++mp[i%M][((ull)A.a<<32)|A.b];
			}
			if(s[i-M]=='L'||s[i-1]=='R')mp[i%M].clear();
		}
		for(auto it:Q[M])is[it]=0;
	}
	printf("%d\n",ans);
	return 0;
}