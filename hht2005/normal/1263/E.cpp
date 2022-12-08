#include<bits/stdc++.h>
using namespace std;
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline long long read() {
	long long x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
inline void gs(char *s) {
	*s=gc();
	while(*s==' '||*s=='\n'||*s=='	')*s=gc();
	while(*s!=' '&&*s!='\n'&&*s!='	')*++s=gc();
	*s='\0';
}
const int maxn=1e6+10;
int s[maxn],Max[maxn<<2],Min[maxn<<2],f[maxn<<2];
inline void tag(int p,int v) {
	Max[p]+=v;
	Min[p]+=v;
	f[p]+=v;
}
inline void pushdown(int p) {
	if(f[p]) {
		tag(p<<1,f[p]);
		tag(p<<1|1,f[p]);
		f[p]=0;
	}
}
inline void updata(int p) {
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return tag(p,v);
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	updata(p);
}
int qry(int x) {
	int p=1,l=1,r=x;
	while(l!=r) {
		pushdown(p);
		int mid=(l+r)>>1;
		l=mid+1;
		p=p<<1|1;
	}
	return Min[p];
}
char opt[maxn];
int main() {
	int n=read(),M=1,m=1;
	gs(opt+1);
	for(int i=1;i<=n;i++) {
		if(opt[i]=='L')m=max(m-1,1);
		if(opt[i]=='R')m++;
		M=max(M,m);
	}
	m=1;
	for(int i=1;i<=n;i++) {
		if(opt[i]=='L')m=max(m-1,1);
		else if(opt[i]=='R')m++;
		else if(opt[i]=='(')add(1,1,M,m,M,-s[m]+1),s[m]=1;
		else if(opt[i]==')')add(1,1,M,m,M,-s[m]-1),s[m]=-1;
		else add(1,1,M,m,M,-s[m]),s[m]=0;
		if(Min[1]<0||qry(M))printf("-1 ");
		else printf("%d ",Max[1]);
	}
	puts("");
	return 0;
}