#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

const int N=1e6+50;
int n,m;
#define fs(x) (Tr[Fa[x]][1]==x)

int Tr[N][2],Fa[N],rev[N],col[N],laz[N];
int su[N];

void Up(int x) {
	int l=Tr[x][0],r=Tr[x][1];
	su[x]=su[l]|su[r];
	if(x>n && col[x]>0) su[x]|=col[x];
}
bool is_root(int x) {
	return Tr[Fa[x]][0]!=x && Tr[Fa[x]][1]!=x;
}
void rotate(int x) {
	int y=Fa[x],f=fs(x);
	if(!is_root(y)) Tr[Fa[y]][fs(y)]=x;
	Fa[x]=Fa[y];
	Fa[y]=x;
	if(Tr[x][!f]) Fa[Tr[x][!f]]=y;
	Tr[y][f]=Tr[x][!f];
	Tr[x][!f]=y;
	Up(y);
	Up(x);
}
void reverse(int x) {
	swap(Tr[x][0],Tr[x][1]);
	rev[x]^=1;
}
void upd(int x,int c) {
	laz[x]=col[x]=c;
	if(c>0 && (Tr[x][0] || Tr[x][1] || x>n)) {
		su[x]=c;
	} else {
		su[x]=0;
	}
}
void down(int x) {
	int l=Tr[x][0],r=Tr[x][1];
	if(rev[x]) {
		if(l) reverse(l);
		if(r) reverse(r);
		rev[x]=0;
	}
	if(laz[x]) {
		if(l) upd(l,laz[x]);
		if(r) upd(r,laz[x]);
		laz[x]=0;
	}
}
void Down(int x) {
	if(!is_root(x)) Down(Fa[x]);
	down(x);
}
void W(int x) {
	Up(x);
	if(!is_root(x)) W(Fa[x]);
}
void Splay(int x) {
	Down(x);
	W(x);
	for(int y; !is_root(x); rotate(x)) {
		if(!is_root(y=Fa[x])) rotate(fs(x)==fs(y)?y:x);
	}
}
void Access(int x) {
	for(int pre=0; x; pre=x,x=Fa[x]) {
		Splay(x);Tr[x][1]=pre;Up(x);
	}
}
void make_root(int x) {
	Access(x);
	Splay(x);
	reverse(x);
}
int find_root(int x) {
	Access(x);
	Splay(x);
	down(x);
	while(Tr[x][0]) {
		x=Tr[x][0];
		down(x);
	}
	Splay(x);
	return x;
}
int u[N],v[N];
bool add(int e) {
	int x=u[e],y=v[e];
	make_root(x);
	if(find_root(y)==x) {
		Splay(x);
		if(su[x]) {
//			if(e==6) cerr << su[x] << endl;
			return 0;
		} else {
			Splay(x);
			upd(x,e);
			return 1;
		}
	} else {
		Splay(x);
		Fa[x]=e+n;
		Fa[e+n]=y;
		return 1;
	}
}
void del(int e) {
	int x=u[e],y=v[e];
	make_root(x);
	Access(y);
	Splay(x);
	int c=su[x];
	if(c==e) {
		upd(x,-1);
	} else {
		if(c>0) del(c);
		
//		if(e==1) cerr << c << endl;
		
		make_root(x);
		Access(y);
		Splay(e+n);
		Fa[x]=0;
		Fa[y]=0;
		Tr[e+n][0]=Tr[e+n][1]=0;
		su[e+n]=col[e+n]=laz[e+n]=rev[e+n]=0;
		
		if(c>0) add(c);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	FOR(i,1,m) scanf("%d%d",&u[i],&v[i]);
	
	ll res=0;
	int r=1;
	FOR(l,1,m) {
		while(r<=m && add(r)) {
			++r;
		}
		res+=r-l;
//		cerr << l << " -- " << r-1 << endl;
		del(l);
	}
	printf("%lld\n",res);
	return 0;
}