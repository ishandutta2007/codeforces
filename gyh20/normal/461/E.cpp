#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct Mat{
	ll a[4][4];
	inline void clr(){memset(a,0x3f,sizeof(a));}
}B[62],C,lst;
ll inf=2e18,ans;
inline void gmn(re ll &x,re ll y){y<x&&(x=y);}
inline Mat mul(Mat A,Mat B){
	Mat C;C.clr();
	for(re int i=0;i<4;++i)
		for(re int j=0;j<4;++j)
			for(re int k=0;k<4;++k)
				gmn(C.a[i][k],min(inf,A.a[i][j]+B.a[j][k]));
	return C;
}
int n,ch[2000002][4],tot;ll m;
char s[100002];
inline void Ins(re char*c,re int x){
	x=min(x,20);
	re int nw=1;
	for(re int i=1;i<=x;++i){
		if(!ch[nw][c[i]-'A'])ch[nw][c[i]-'A']=++tot;
		nw=ch[nw][c[i]-'A'];
	}
}
inline void dfs(re int x,re int y,re char fst,re char lst){
	if(!x)return gmn(B[0].a[fst][lst],y-1);
	for(re int i=0;i<4;++i){
		if(x==1)fst=i;
		dfs(ch[x][i],y+1,fst,i);
	}
}
int main(){
	m=read(),scanf("%s",s+1),n=strlen(s+1),B[0].clr(),tot=1,C.clr();
	for(re int i=1;i<=n;++i)Ins(s+i-1,n-i+1);dfs(1,0,0,0);
	for(re int i=0;i<4;++i)C.a[0][i]=0;
	re int mx=0;
	for(re int i=1;i<=60;++i){
		B[i]=mul(B[i-1],B[i-1]);
		re bool ia=1;
		for(re int j=0;j<4;++j)ia&=C.a[0][j]>=m;
		if(ia)break;
		mx=i;
	}
	for(re int i=mx;~i;--i){
		lst=C,C=mul(C,B[i]);
		re bool ia=1;
		for(re int j=0;j<4;++j)ia&=C.a[0][j]>=m;
		if(ia)C=lst;
		else ans+=1ll<<i;
	}
	printf("%lld",ans+1);
}