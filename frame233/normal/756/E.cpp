#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,MAXN=10005,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
char ss[MAXN];int a[N],b[N],c[N],f[N],g[N],d[N];ll m[MAXN];
int main(){
	int n;read(n);
	for(int i=2;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	scanf("%s",ss+1);int len=strlen(ss+1),L=0;
	for(int i=len;i>=1;i-=5){++L;for(int j=0,c=1;j<5&&i-j>=1;++j)m[L]=m[L]+c*(ss[i-j]-'0'),c*=10;}
	for(int i=1;i<n;++i){
		if(a[i+1]==1){c[i]=0;continue;}
		ll rest=0;for(int j=L;j>=1;--j)rest=100000LL*rest+m[j],m[j]=rest/a[i+1],rest-=m[j]*a[i+1];
		c[i]=rest;while(L&&!m[L])--L;
	}
	ll val=0;for(int j=L;j>=1;--j){val=100000LL*val+m[j];if(val>1e9)break;}
	c[n]=std::min((ll)1e9,val),f[0]=1,a[1]=1;int s=0;
	if(c[n]>3e5)return puts("0"),0;
	for(int i=1;i<n;++i)d[i+1]=d[i]/a[i]+b[i]-c[i];
	for(int i=1;i<=n;++i)if(d[i]<0)return puts("0"),0;
	ll sum=0;for(int i=1;i<=n;++i)sum+=d[i];
	for(int i=n;i>=1;--i){
		memset(g,0,(d[i]/a[i]+3)<<2);
		for(int j=0;j<=s;++j)if(f[j]){
			int l=std::max(0,j+c[i]-b[i]),r=std::min(d[i]/a[i],j+c[i]);
			if(l<=r)add(g[l],f[j]),sub(g[r+1],f[j]);
		}
		for(int j=1,lim=d[i]/a[i];j<=lim;++j)add(g[j],g[j-1]);
		memset(f,0,(d[i]+3)<<2),s=d[i];
		for(int j=0,lim=d[i]/a[i];j<=lim;++j)f[j*a[i]]=g[j];
	}
	printf("%d\n",f[0]);
	return 0;
}