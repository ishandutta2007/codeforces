// LUOGU_RID: 90811523
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int len;
struct Mat{
	int a[36][36];
	inline void clr(){memset(a,0,sizeof(a));}
}Base;
inline Mat mul(Mat A,Mat B){
	Mat C;C.clr();
	for(re int i=1;i<=len;++i)
		for(re int j=1;j<=len;++j)
			for(re int k=1;k<=len;++k)
				C.a[i][k]^=A.a[i][j]&B.a[j][k];
	return C;
}
char s[100002];
int n,od[42],nw[42];
long long S,X,ans;
map<ll,int>B;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	int pos=1;
	while(s[pos]=='0')++pos;
	if(pos>n)return puts("-1"),0;
	while(s[n]=='0')--n;
	for(re int i=pos;i<=n;++i)S+=(1ll*(s[i]-'0'))<<(i-pos);
	if(S==1)return printf("%d %d\n",pos,pos+1),0;
	len=n-pos+1;
	for(re int i=2;i<=len;++i)Base.a[i][i-1]=1;
	for(re int i=2;i<=len;++i)Base.a[1][i-1]=(S>>(i-1))&1;
	for(re int i=1;i<=17;++i)Base=mul(Base,Base);
	ll tt=1;
	for(re int i=0;i<=131072;++i){
		B[tt]=i;
		if(tt&1)tt^=S;
		tt>>=1;
	}
	X=S>>1,ans=0;
	for(re int i=0;i<=200000;++i){
		if(i&&B.count(X)){
			printf("%d %lld\n",pos,pos+131072ll*(i)-B[X]+1);
			return 0;
		}
		for(re int j=1;j<=len;++j)od[j]=(X>>(j-1))&1,nw[j]=0;
		for(re int x=1;x<=len;++x)
			for(re int y=1;y<=len;++y)
				nw[y]^=od[x]&Base.a[x][y];
		X=0;
		for(re int j=1;j<=len;++j)X+=(1ll<<j-1)*nw[j];
	}
	puts("-1");
}