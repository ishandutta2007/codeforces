#include<bits/stdc++.h>
using namespace std;
#define enter pc('\n')
#define space pc(' ')
#define Rg register
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(; ch<'0'||ch>'9'; ch=gc())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
#define fl fwrite(o_str,1,o_t,stdout),o_t=0
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)fl;
}
inline void write(int x) {
	if(x<0)x=-x,pc('-');
	if(x>9)write(x/10);
	pc(x%10^48);
}
const int N=1e5+10;
int a[N*10],val[N*5],fa[N],siz[N],rt[N],T,mx,tag,l,r;
int op[N*5],L[N*5],R[N*5],x[N*5],ans[N*5],ql,qr,X;
inline int get(int x) {
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
inline void build() {
	mx=tag=0;
	memset(rt,0,sizeof(rt));
	memset(siz,0,sizeof(siz));
	for(Rg int i=l;i<=r;i++) {
		if(rt[a[i]])fa[i]=rt[a[i]];
		else {
			fa[i]=rt[a[i]]=i;
			val[i]=a[i];
		}
		mx=max(mx,a[i]);
		siz[a[i]]++;
	}
}
inline void rebuild() {
	if(X==0)return;
	Rg int i;
	for(i=l;i+3<=r;i+=4) {
		a[i]=val[get(i)];
		rt[a[i]]=siz[a[i]]=0;
		a[i]-=tag;
		a[i+1]=val[get(i+1)];
		rt[a[i+1]]=siz[a[i+1]]=0;
		a[i+1]-=tag;
		a[i+2]=val[get(i+2)];
		rt[a[i+2]]=siz[a[i+2]]=0;
		a[i+2]-=tag;
		a[i+3]=val[get(i+3)];
		rt[a[i+3]]=siz[a[i+3]]=0;
		a[i+3]-=tag;
	}
	for(;i<=r;i++) {
		a[i]=val[get(i)];
		rt[a[i]]=siz[a[i]]=0;
		a[i]-=tag;
	}
	for(Rg int i=l;i<=r;i+=8) {
		val[i]=0;
		val[i+1]=0;
		val[i+2]=0;
		val[i+3]=0;
		val[i+4]=0;
		val[i+5]=0;
		val[i+6]=0;
		val[i+7]=0;
	}
	mx=tag=0;
	int R=min(r,qr);
	for(i=max(l,ql);i+3<=R;i+=4) {
		a[i]=a[i]>X?a[i]-X:a[i];
		a[i+1]=a[i+1]>X?a[i+1]-X:a[i+1];
		a[i+2]=a[i+2]>X?a[i+2]-X:a[i+2];
		a[i+3]=a[i+3]>X?a[i+3]-X:a[i+3];
	}
	for(;i<=R;i++)a[i]=a[i]>X?a[i]-X:a[i];
	for(i=l;i<=r;i++) {
		if(rt[a[i]])fa[i]=rt[a[i]];
		else {
			fa[i]=rt[a[i]]=i;
			val[i]=a[i];
		}
		if(mx<a[i])mx=a[i];
		siz[a[i]]++;
	}
}
inline void merge(int x,int y) {
	if(rt[y]) {
		if(siz[rt[y]]>siz[rt[x]])fa[rt[x]]=rt[y];
		else fa[rt[y]]=rt[x],rt[y]=rt[x];
	} else rt[y]=rt[x];
	val[rt[y]]=y;
	siz[y]+=siz[x];
	rt[x]=siz[x]=0;
}
inline void modify() {
	if(X==0)return;
	if(mx-tag>2*X) {
		Rg int i;
		for(i=tag;i+3<=X+tag;i+=4) {
			if(rt[i])merge(i,i+X);
			if(rt[i+1])merge(i+1,i+1+X);
			if(rt[i+2])merge(i+2,i+2+X);
			if(rt[i+3])merge(i+3,i+3+X);
		}
		for(;i<=X+tag;i++)
			if(rt[i])merge(i,i+X);
		tag+=X;
	} else {
		Rg int i;
		for(i=X+1+tag;i+3<=mx;i+=4) {
			if(rt[i])merge(i,i-X);
			if(rt[i+1])merge(i+1,i+1-X);
			if(rt[i+2])merge(i+2,i+2-X);
			if(rt[i+3])merge(i+3,i+3-X);
		}
		for(;i<=mx;i++)
			if(rt[i])merge(i,i-X);
		if(X+tag<mx)mx=X+tag;
	}
}
inline void get_ans(int I) {
	if(X+tag>100001)return;
	if(ql<=l&&r<=qr)ans[I]+=siz[X+tag];
	else {
		int R=min(r,qr);
		Rg int i;
		for(i=max(l,ql);i+3<=R;i+=4) {
			if(val[get(i)]==tag+X)ans[I]++;
			if(val[get(i+1)]==tag+X)ans[I]++;
			if(val[get(i+2)]==tag+X)ans[I]++;
			if(val[get(i+3)]==tag+X)ans[I]++;
		}
		for(;i<=R;i++)
			if(val[get(i)]==tag+X)ans[I]++;
	}
}
int main() {
	int n=read(),m=read();
	T=sqrt(n-1)+1;
	for(Rg int i=1;i<=n;i++)
		a[i]=read();
	for(Rg int i=1;i<=m;i++)
		op[i]=read(),L[i]=read(),R[i]=read(),x[i]=read();
	for(Rg int I=1;I<=n;I+=T) {
		l=I,r=min(I+T-1,n);
		build();
		for(Rg int i=1;i<=m;i++) {
			ql=L[i],qr=R[i],X=x[i];
			if(qr<l||ql>r)continue;
			if(op[i]==1) {
				if(ql>l||qr<r)rebuild();
				else modify();
			} else get_ans(i);
		}
	}
	for(Rg int i=1;i<=m;i++)
		if(op[i]==2)write(ans[i]),enter;
	return fl;
}