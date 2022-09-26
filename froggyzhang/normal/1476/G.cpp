#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int B=2500;
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,m1,m2,pos[N],cnt[N],g[N],a[N],ans[N];
struct Query{
	int id,l,r,k,t;
	friend bool operator <(const Query a,const Query b){
		return pos[a.l]==pos[b.l]?(pos[a.r]==pos[b.r]?a.t<b.t:a.r<b.r):a.l<b.l;
	}
}q[N];
int qwq;
struct Change{
	int p,val;
}c[N];
struct Hash_Table{
	int head[2333],nxt[N];
	const int base=2333;
	void insert(int x){
		int u=x%base;
		nxt[x]=head[u];
		head[u]=x;
	}
	void erase(int x){
		int u=x%base;
		if(head[u]==x)head[u]=nxt[x];
		else{
			for(int t=head[u];nxt[t];t=nxt[t]){
				if(nxt[t]==x){nxt[t]=nxt[x];break;}
			}
		}
		nxt[x]=0;
	}
	void Get(int *b,int &len){
		len=0;
		for(int u=0;u<base;++u){
			for(int x=head[u];x;x=nxt[x]){
				b[++len]=x;
			}
		}
	}
}s;
inline void Add(int x){
	++qwq;
	if(cnt[a[x]]>=1&&!--g[cnt[a[x]]])s.erase(cnt[a[x]]);
	++cnt[a[x]];
	if(cnt[a[x]]>=1&&!g[cnt[a[x]]]++)s.insert(cnt[a[x]]);
}
inline void Del(int x){
	++qwq;
	if(cnt[a[x]]>=1&&!--g[cnt[a[x]]])s.erase(cnt[a[x]]);
	--cnt[a[x]];
	if(cnt[a[x]]>=1&&!g[cnt[a[x]]]++)s.insert(cnt[a[x]]);
}
int Query(int l,int r,int k){
	static int b[N],len;
	int ans=inf;
	s.Get(b,len);
	sort(b+1,b+len+1);
	for(int i=1,j=1;i<=len;++i){
		k-=g[b[i]];
		while(k+g[b[j]]<=0)k+=g[b[j++]];
		if(k<=0)ans=min(ans,b[i]-b[j]);
	}
	return ans==inf?-1:ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	g[0]=n+1;
	for(int i=1;i<=m;++i){
		int opt=read();
		if(opt==1){
			int l=read(),r=read(),k=read();++m1;
			q[m1]={m1,l,r,k,m2};
		}
		else{
			int x=read(),y=read();
			c[++m2]={x,y};
		}
	}
	for(int i=1;i<=n;++i)pos[i]=i/B;
	sort(q+1,q+m1+1);
	for(int i=1,l=1,r=0,t=0;i<=m1;++i){
		int ql=q[i].l,qr=q[i].r,qt=q[i].t;
		while(l>ql)Add(--l);
		while(r<qr)Add(++r);
		while(l<ql)Del(l++);
		while(r>qr)Del(r--);
		auto Swap = [&](int x)->void{
			if(c[x].p>=l&&c[x].p<=r)Del(c[x].p);
			swap(c[x].val,a[c[x].p]);
			if(c[x].p>=l&&c[x].p<=r)Add(c[x].p);
		};
		while(t<qt)Swap(++t);
		while(t>qt)Swap(t--);
		ans[q[i].id]=Query(q[i].l,q[i].r,q[i].k);
	}
	for(int i=1;i<=m1;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}