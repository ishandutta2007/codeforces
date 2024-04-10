#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,B=500;typedef long long ll;
int pool[N],*P=pool,to[N];
int n,p[N],O[N],X[N],Y[N],cyc[N],pos,all[N],ap;bool mark[N],vis[N];int bel[N],*nd[N],c[N];ll val[N],s[N],S[N];
void solve(int l,int r){
	memset(mark,0,n+3),memset(vis,0,n+3),memset(bel,0,(n+3)<<2);P=pool;
	for(int i=l;i<=r;++i){
		if(O[i]==2)mark[X[i]]=1;
		else if(O[i]==3)mark[X[i]]=mark[Y[i]]=1;
	}
	ap=0;for(int i=1;i<=n;++i)if(mark[i])all[++ap]=i,c[i]=0,val[i]=0;
	for(int i=1;i<=n;++i)if(!vis[i]){
		pos=0;for(int u=i;!vis[u];u=p[u])cyc[pos++]=u,vis[u]=1;
		int x=-1;for(int i=0;i<pos;++i)if(mark[cyc[i]]){x=cyc[i];break;}
		if(x==-1)continue;
		for(int j=pos-1;j>=0;--j){
			if(mark[cyc[j]])to[cyc[j]]=x,x=cyc[j];
			bel[cyc[j]]=x,++c[x];
		}
	}
	for(int i=1;i<=n;++i)if(mark[i])nd[i]=P,P+=c[i],c[i]=0;
	for(int i=1;i<=n;++i)if(bel[i])nd[bel[i]][c[bel[i]]++]=i;
	for(int i=l;i<=r;++i){
		int o=O[i],x=X[i],y=Y[i];
		if(o==1){
			ll ans=s[y]-s[x-1];
			for(int j=1;j<=ap;++j){
				int o=all[j];
				ans+=(std::upper_bound(nd[o],nd[o]+c[o],y)-std::lower_bound(nd[o],nd[o]+c[o],x))*val[o];
			}
			printf("%lld\n",ans);
		}
		else if(o==2){
			int u=x,tmp=u;
			do{val[u]+=y,u=to[u];}while(u!=tmp);
		}
		else std::swap(to[x],to[y]),std::swap(p[x],p[y]);
	}
	for(int i=1;i<=n;++i)S[i]=bel[i]?val[bel[i]]:0,S[i]+=S[i-1];
	for(int i=1;i<=n;++i)s[i]+=S[i];
}
int main(){
	read(n);for(int i=1;i<=n;++i)read(s[i]),s[i]+=s[i-1];
	for(int i=1;i<=n;++i)read(p[i]);
	int q;read(q);for(int i=1;i<=q;++i)read(O[i],X[i],Y[i]);
	for(int l=1,r=B;l<=q;l+=B,r+=B)r=std::min(r,q),solve(l,r);
	return 0;
}