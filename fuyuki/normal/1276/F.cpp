#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1;
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
namespace ST{
	int lg[N],t[20][N];
	V build(int*a,int n){
		copy(a+1,a+1+n,t[0]+1);
		FOR(i,2,n)lg[i]=lg[i>>1]+1;
		FOR(i,1,19)FOR(j,1,n-(1<<i))t[i][j]=min(t[i-1][j],t[i-1][j+(1<<i-1)]);
	}
	I ask(int l,int r){
		int p=lg[r-l];
		return min(t[p][l],t[p][r-(1<<p)]);
	}
}
namespace SA{
	int n,m,sa[N],x[N],y[N],c[N],h[N];char*st;
	V input(char*a,int len){
		n=len,m=128,st=a;
		FOR(i,1,n)x[i]=st[i],sa[i]=i;
	}
	V radix_sort(){
		FOR(i,1,m)c[i]=0;
		FOR(i,1,n)c[x[i]]++;
		FOR(i,1,m)c[i]+=c[i-1];
		ROF(i,n,1)sa[c[x[y[i]]]--]=y[i];
	}
	V init(){
		for(int k=0,p=0;k<=n;k=k<<1|!k){
			FOR(i,n-k+1,n)y[++p]=i;
			FOR(i,1,n)if(sa[i]>k)y[++p]=sa[i]-k;
			radix_sort(),swap(x,y),p=0;
			FOR(i,1,n)
				x[sa[i]]=p+=y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k];
			if(p>=n)break;m=p,p=0;
		}
		FOR(i,1,n){
			int&p=h[x[i]]=max(0,h[x[i-1]]-1);
			while(st[i+p]==st[sa[x[i]+1]+p])h[x[i]]++;
		}
		ST::build(h,n);
	}
}
struct tree{
	set<int>mp;ll val;
	V init(){mp.clear(),mp.insert(0),mp.insert(N),val=0;}
	I pre(int x){return*--mp.lower_bound(x);}
	I nxt(int x){return*mp.upper_bound(x);}
	V add(int x,int y,int w){if(x&&y!=N)val+=ST::ask(x,y)*w;}
	V ins(int x){
		int p=pre(x),q=nxt(x);
		add(p,q,1),add(p,x,-1),add(x,q,-1),mp.insert(x);
	}
}t[N];
namespace SAM{
	int n,tot,last,top;
	int fa[N],len[N],ch[N][26],d[N],sta[N],pos[N];
	V cpy(int x,int y){FOR(i,0,25)ch[x][i]=ch[y][i];}
	V ins(int x){
		int p(last),np,q,nq;
		len[np=last=++tot]=len[p]+1;
		while(p&&!ch[p][x])ch[p][x]=np,p=fa[p];
		if(!p)return void(fa[np]=1);
		if(len[q=ch[p][x]]==len[p]+1)return void(fa[np]=q);
		cpy(nq=++tot,q),len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
		while(p&&ch[p][x]==q)ch[p][x]=nq,p=fa[p];
	}
	V input(char*a,int len){
		n=len,tot=last=pos[0]=1;
		FOR(i,1,n)ins(a[i]-'a'),pos[i]=last;
	}
	V merge(tree&x,tree&y){
		if(x.mp.size()<y.mp.size())swap(x,y);
		for(int v:y.mp)if(v&&v!=N)x.ins(v),x.val+=n-SA::sa[v]+1;
	}
	V work(){
		ll ans=0;
		FOR(i,0,tot)d[fa[i]]++,t[i].init();
		FOR(i,1,tot)if(!d[i])sta[++top]=i;
		FOR(i,0,n-2)t[pos[i]].ins(SA::x[i+2]),t[pos[i]].val+=n-i-1;
		FOR(i,1,tot)ans+=len[i]-len[fa[i]]<<(i!=pos[n]);
		while(int u=sta[top--]){
			ans+=t[u].val*(len[u]-len[fa[u]]);
			if(fa[u])merge(t[fa[u]],t[u]);
			if(!--d[fa[u]])sta[++top]=fa[u];
		}
		cout<<ans+t[1].val+2;
	}
};
int n;
char a[N];
int main(){
	scanf("%s",a+1),n=strlen(a+1),SA::input(a,n);
	SA::init(),SAM::input(a,n),SAM::work();
	return 0;
}