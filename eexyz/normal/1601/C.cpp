#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define N 1000004
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define L(x) (x&-x)
int tg[N<<2],mn[N<<2],c[N];
long long ans;
void add(int x,int y){while(x<N)c[x]+=y,x+=L(x);}
int sum(int x){int ret=0;while(x)ret+=c[x],x-=L(x);return ret;}
void up(int k){
	mn[k]=min(mn[ls],mn[rs]);
}
void mem(int k,int l,int r){
	tg[k]=mn[k]=0;
	if(l==r)return ;
	mem(ls,l,mid);mem(rs,mid+1,r);
}
void down(int k){
	if(tg[k]){
		mn[ls]+=tg[k];
		mn[rs]+=tg[k];
		tg[ls]+=tg[k];
		tg[rs]+=tg[k];
		tg[k]=0;
	}
}
void modify(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		tg[k]+=v;mn[k]+=v;return ;
	}
	if(x>r||y<l)return ;
	down(k);
	modify(ls,l,mid,x,y,v);modify(rs,mid+1,r,x,y,v);up(k);
}
char buf[100000],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
struct node{
	int v,pos;
}A[N];
inline bool cmp(node aa,node bb){return aa.v<bb.v;}
int T,n,m,i,a[N],b[N],j1,j2,cnt; 
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i],A[i].v=a[i],A[i].pos=i,modify(1,0,n,i,n,1);
		for(i=1;i<=m;++i)cin>>b[i];
		sort(b+1,b+m+1);sort(A+1,A+n+1,cmp);
		ans=0;
		for(j1=j2=i=1;i<=m;++i){
			while(j1<=n&&A[j1].v<b[i]){
				modify(1,0,n,0,A[j1].pos-1,1);
				++j1; 
			}
			while(j2<=n&&A[j2].v<=b[i]){
				modify(1,0,n,A[j2].pos,n,-1);
				++j2;
			}
			ans+=mn[1];
		}
		mem(1,0,n);
		cnt=0;
		for(i=1;i<=n;++i){
			if(A[i].v!=A[i-1].v)++cnt;
			a[A[i].pos]=cnt;
		}
		for(i=1;i<=n;++i){
			add(a[i],1);
			ans+=i-sum(a[i]);
		}
		for(i=1;i<=n;++i){
			add(a[i],-1);
		}
		cout<<ans<<"\n";
	}
}