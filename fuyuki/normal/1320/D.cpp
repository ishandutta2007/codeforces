#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e5+1,mod=1e9+7;
int n,m,pw[N];
char st[N];
struct data{
	int val,len;
	V clean(){val=len=0;}
	data operator+(const data&u)const{
		return(data){(int)((1ll*pw[len]*u.val+val)%mod),len+u.len};
	}
	B operator==(const data&u)const{
		return val==u.val&&len==u.len;
	}
}one;
struct node{
	int cntl,cntr,len,tag;
	data str;
	B operator==(const node&u)const{
		return tag==u.tag&&cntl==u.cntl&&cntr==u.cntr&&str==u.str&&len==u.len;              
	}
}t[N<<2];
node add(node x,node y){
	static node out;
	out.len=x.len+y.len;
	if(out.tag=x.tag&&y.tag){
		out.cntl=out.cntr=0;
		out.str=x.str+y.str;
		return out;
	}
	if(x.tag){
		out.cntl=x.len+y.cntl;
		out.cntr=y.cntr;
		out.str=y.str;
		return out;
	}
	if(y.tag){
		if(x.cntr+y.len&1)
			out.cntr=1,out.cntl=x.cntl+x.cntr+y.len-1;
		else
			out.cntr=0,out.cntl=x.cntl+x.cntr+y.len;
		out.str=x.str;
		return out;
	}
	int flag=x.cntr+y.cntl&1;
	out.cntl=x.cntl+x.cntr+y.cntl-flag;
	out.cntr=y.cntr;
	if(flag)
		out.str=x.str+one+y.str;
	else out.str=x.str+y.str;
	return out;
}
V input(){
	scanf("%d%s",&n,st+1);
	one.val=one.len=1;
}
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V check(int&x){x-=mod,x+=x>>31&mod;}
V build(int p,int L,int R){
	if(L==R){
		t[p].len=1;
		if(st[L]=='0')t[p].str.len=1;
		if(st[L]=='1')t[p].tag=1;
		return;
	}
	int mid=L+R>>1;
	build(lson),build(rson);
	t[p]=add(t[lc],t[rc]);
}
node ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p];
	int mid=L+R>>1;
	if(r<=mid)return ask(lson,l,r);
	if(l>mid)return ask(rson,l,r);
	return add(ask(lson,l,mid),ask(rson,mid+1,r));
}
V init(){
	pw[0]=1;
	FOR(i,1,n)pw[i]=2ll*pw[i-1]%mod;
	build(root);
}
V work(){
	int l1,l2,r1,r2,len;
	m=getint();
	node tmpx,tmpy;
	while(m--){
		l1=getint(),l2=getint(),len=getint();
		r1=l1+len-1,r2=l2+len-1;
		if(ask(root,l1,r1)==ask(root,l2,r2))
			cout<<"Yes\n";
		else cout<<"No\n";
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}