#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second

const int N=1e5+100,maxn=17,lim=262142;
int a[N],he=0;

int mymin(int x,int y) {return (x<y?x:y);}
int mymax(int x,int y) {return (x>y?x:y);}

struct tree{
	int l,r,lc,rc,L[19],R[19];
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void Change(int now,int k,int c1,int c2,int ty){
	he++;
	if(tr[now].l==tr[now].r){
		tr[now].L[ty]=c1;tr[now].R[ty]=c2;
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) Change(lc,k,c1,c2,ty);
	else Change(rc,k,c1,c2,ty);
	tr[now].L[ty]=mymin(tr[lc].L[ty],tr[rc].L[ty]);
	tr[now].R[ty]=mymax(tr[lc].R[ty],tr[rc].R[ty]);
}

struct node{
	int l,r;
	node() {}
	node(int _l,int _r) {l=_l;r=_r;}
};
node tmp;
void findans(int now,int l,int r,int ty){
	if(l>r) return ;he++;
	if(l==tr[now].l&&r==tr[now].r){
		tmp=node(mymin(tmp.l,tr[now].L[ty]),mymax(tmp.r,tr[now].R[ty]));
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) findans(lc,l,r,ty);
	else if(mid<l) findans(rc,l,r,ty);
	else{
		findans(lc,l,mid,ty);findans(rc,mid+1,r,ty);
	}
}

int g1[N][19],g2[N][19];

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;

int main()
{
	
	int n,q;
	gi(n);gi(q);
	
	for(int i=1;i<=n;i++) gi(a[i]);
	
	build(1,n-1);
	for(int i=1;i<n;i++){
		g1[i][0]=mymin(a[i],a[i+1]);g2[i][0]=mymax(a[i],a[i+1]);
		Change(1,i,g1[i][0],g2[i][0],0);
	}
	
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<n;j++){
			tmp=node(1e9,-1e9);
			findans(1,g1[j][i-1],g2[j][i-1]-1,i-1);
			node t=tmp;
			g1[j][i]=t.l;g2[j][i]=t.r;
			Change(1,j,g1[j][i],g2[j][i],i);
		}
	}
	
	cerr<<clock()<<endl;
	
	cerr<<he<<endl;
	
	
	for(int i=1;i<=q;i++){
		int l,r;
		gi(l);gi(r);
		
		if(l==1&&r==n){
			print(0);putc('\n');
			continue;
		}
		if(l==r){
			print(-1);putc('\n');
			continue;
		}
		
		int Ans=0;
		for(int j=maxn;j>=0;j--){
			tmp=node(1e9,-1e9);
			findans(1,l,r-1,j);
			node t=tmp;
			if(t.l!=1||t.r!=n){
				l=t.l;r=t.r;
				Ans=(Ans+(1<<j));
				continue;
			}
		}
		
		if(Ans<=lim) print(Ans+1);
		else print(-1);
		putc('\n');
	}
	
	cerr<<he<<endl;
	
	return 0;
}