#include<bits/stdc++.h>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=5e5+1;
int n,tot,val[N];
I find(rnt x){
	rnt l=1,r=tot,mid;
	while(mid=l+r>>1,l^r)
		if(x>=val[mid+1])
			l=mid+1;
		else r=mid;
	return mid;
}
struct node{
	int lx,rx,ly,ry;
	V input(){
		lx=getint(),rx=getint();
		ly=getint(),ry=getint();
		val[++tot]=lx,val[++tot]=rx;
		val[++tot]=ly,val[++tot]=ry;
	}
	V init(){
		lx=find(lx),rx=find(rx);
		ly=find(ly),ry=find(ry);
	}
	V rot(){swap(lx,ly),swap(rx,ry);}
	V rev(){
		lx=tot+1-lx,rx=tot+1-rx,swap(lx,rx);
	}
}a[N];
vector<int>add[N],ask[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i].input();
}
V init(){
	sort(val+1,val+1+tot);
	tot=unique(val+1,val+1+tot)-val-1;
	FOR(i,1,n)a[i].init();
}
int tag[N<<2];
#define lc p<<1
#define rc p<<1|1
#define root 1,1,tot
#define lson lc,L,mid
#define rson rc,mid+1,R
B test(rnt p,rnt L,rnt R,rnt l,rnt r){
	if(L==l&&R==r)return tag[p];
	rnt mid=L+R>>1;
	if(r<=mid)return test(lson,l,r);
	if(l>mid)return test(rson,l,r);
	return test(lson,l,mid)||test(rson,mid+1,r);
}
V modify(rnt p,rnt L,rnt R,rnt l,rnt r){
	tag[p]=1;
	if(L==l&&R==r)return;
	rnt mid=L+R>>1;
	if(r<=mid)return modify(lson,l,r);
	if(l>mid)return modify(rson,l,r);
	return modify(lson,l,mid),modify(rson,mid+1,r);
}
V once(){
	FOR(i,1,tot)add[i].clear(),ask[i].clear();
	FOR(i,1,n)ask[a[i].lx].push_back(i),add[a[i].rx].push_back(i);
	FOR(i,1,tot){
		for(int p:ask[i])
			if(test(root,a[p].ly,a[p].ry))
				cout<<"NO",exit(0);
		for(int p:add[i])
			modify(root,a[p].ly,a[p].ry);
	}
}
V work(){
	once();
	memset(tag,0,sizeof(tag));
	FOR(i,1,n)a[i].rev();
	once();
	memset(tag,0,sizeof(tag));
	FOR(i,1,n)a[i].rot();
	once();
	memset(tag,0,sizeof(tag));
	FOR(i,1,n)a[i].rev();
	once();
	cout<<"YES";
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}