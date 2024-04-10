#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef long long ll;const ll INF=1e18;typedef __int128 LL;
int a[N],t[5],ans[N];ll f[N][5];LL sum[N];
inline bool cmp(int x,int y){return a[x]<a[y];}
inline ll get(int l,int r){return std::min((LL)INF,sum[l]-sum[r]);}
struct node{ll l,r;};
inline node merge(ll s,const node &a,const node &b){
	node c;c.l=std::max(a.l,b.l+s),c.r=std::min(a.r,b.r+s);
	c.l=std::min(c.l,INF+1),c.r=std::min(c.r,INF);
	return c;
}
node w[N][20];
struct qry{ll x;int y,p,id;};
std::vector<qry> v[5];
void MAIN(){
	for(int i=0;i<5;++i)v[i].clear();
	memset(sum,0,sizeof(sum));
	int n,K,q;read(n,K,q);
	for(int i=1;i<=n;++i)read(a[i]);
	ll x;int y;
	for(int t=1;t<=q;++t){
		read(y,x);if(x>f[n][K]){ans[t]=-1;continue;};
		v[K].pb({x,y,1,t});
	}
	for(int L=K;L>=0;--L){
		if(L==0){
			for(const auto &it:v[L])ans[it.id]=a[it.y];
			continue;
		}
		for(int i=n;i>=1;--i){
			int lim=std::min(L,n-i);ll s=0;
			for(int j=1;j<=lim;++j)if(a[i+j]<a[i])s+=f[n-i-j][L-j];
			s=std::min(s,INF);w[i][0]={s+1,std::min(INF,s+f[n-i][L])},sum[i]=sum[i+1]+s;
			for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)w[i][j]=merge(get(i,i+(1<<(j-1))),w[i][j-1],w[i+(1<<(j-1))][j-1]);
		}
		for(const auto &it:v[L]){
			x=it.x,y=it.y;int p=it.p,id=it.id;
			node cur={0,INF};
			for(int j=19;j>=0;--j)if(p+(1<<j)<=n+1){
				node tmp=merge(get(it.p,p),cur,w[p][j]);
				if(tmp.l<=x&&x<=tmp.r)cur=tmp,p+=1<<j;
			}
			if(y<p){ans[id]=a[y];continue;}
			x-=get(it.p,p);
			int pos=0;for(int j=0;j<=L&&p+j<=n;++j)t[pos++]=p+j;
			std::sort(t,t+pos,cmp);
			for(int _=0;_<pos;++_){
				int i=t[_];ll c=f[n-i][L-(i-p)];
				if(x<=c){
					if(y<=i){ans[id]=a[i-(y-p)];break;}
					v[L-(i-p)].pb({x,y,i+1,id}),p=i+1;break;
				}
				else x-=c;
			}
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
}
int main(){
	f[0][0]=f[0][1]=f[0][2]=f[0][3]=f[0][4]=1;
	for(int i=1;i<N;++i)for(int j=0;j<=4;++j){
		for(int k=0;k<=j&&k<i;++k)f[i][j]+=f[i-k-1][j-k];
		f[i][j]=std::min(f[i][j],INF);
	}
	int _;read(_);
	while(_--)MAIN();
	return 0;
}