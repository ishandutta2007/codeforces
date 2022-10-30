#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10000005,M=(1<<20)-1;
int ch[N][2],s0[N],s1[N],siz[N],tag[N],dep[N],nc,rt;
inline void pushup(int u){
	siz[u]=siz[ch[u][0]]+siz[ch[u][1]];
	s0[u]=s0[ch[u][0]]|s0[ch[u][1]];
	s1[u]=s1[ch[u][0]]&s1[ch[u][1]];
}
inline void upd(int u,int C){
	if(!u)return;
	tag[u]^=C;
	if(~dep[u]&&(C>>dep[u]&1))std::swap(ch[u][0],ch[u][1]);
	int x=(s0[u]&(~C))|((~s1[u])&C),y=((~s0[u])&C)|(s1[u]&(~C));
	s0[u]=x,s1[u]=y;
}
inline void pushdown(int u){if(tag[u])upd(ch[u][0],tag[u]),upd(ch[u][1],tag[u]),tag[u]=0;}
void ins(int &u,int x,int d){
	if(!u)dep[u=++nc]=d;
	if(d==-1)return s0[u]=x,s1[u]=x,siz[u]=1,void();
	ins(ch[u][x>>d&1],x,d-1),pushup(u);
}
void split(int &x,int &y,int L,int R,int l,int r){
	if(!x)return y=0,void();
	if(L<=l&&r<=R)return y=x,x=0,void();
	int mid=(l+r)>>1;pushdown(x),dep[y=++nc]=dep[x];
	if(L<=mid)split(ch[x][0],ch[y][0],L,R,l,mid);
	if(R>mid)split(ch[x][1],ch[y][1],L,R,mid+1,r);
	pushup(x),pushup(y);
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	if(dep[a]==-1)return siz[a]|=siz[b],a;
	pushdown(a),pushdown(b);
	ch[a][0]=merge(ch[a][0],ch[b][0]);
	ch[a][1]=merge(ch[a][1],ch[b][1]);
	return pushup(a),a;
}
void OR(int u,int C){
	if(!u)return;
	if((s0[u]&C)==(s1[u]&C))return upd(u,(s0[u]|C)^s0[u]);
	pushdown(u);
	if(C>>dep[u]&1)upd(ch[u][0],1<<dep[u]),ch[u][1]=merge(ch[u][1],ch[u][0]),C^=1<<dep[u],ch[u][0]=0;
	OR(ch[u][0],C),OR(ch[u][1],C),pushup(u);
}
int main(){
	std::fill(s1,s1+N,M);
	int n,q;read(n,q);
	for(int i=0,x;i<n;++i)read(x),ins(rt,x,19);
	int opt,l,r,x,p;
	while(q--){
		read(opt,l,r);
		split(rt,p,l,r,0,M);
		if(opt==4)printf("%d\n",siz[p]);
		else{
			read(x);
			if(opt==1)upd(p,M),OR(p,x^M),upd(p,M);
			else if(opt==2)OR(p,x);
			else upd(p,x);
		}
		rt=merge(rt,p);
	}
	return 0;
}