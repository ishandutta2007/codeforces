#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int mo=998244353;
const int yg=3;
int tot,m,M,a[N],b[N],t[N],g[30],ng[30];
vector<int>p[N];
int qk(int x,int y){int r=1;
	for(;y;y>>=1){
		if(y&1)r=(ll)r*x%mo;x=(ll)x*x%mo;
	}return r;
}
void ntt(int*a,int n,bool t){int j=0;
	rep(i,1,n-2){
		for(int s=n;j^=s>>=1,~j&s;);
		if(i<j)swap(a[i],a[j]);
	}
	for(int d=0;(1<<d)<n;++d){
		int m=1<<d,m2=m<<1,_w=t==1?g[d]:ng[d];
		for(int i=0;i<n;i+=m2){int w=1;
			rep(j,0,m-1){
				int &A=a[i+j+m],&B=a[i+j],t=(ll)w*A%mo;
				w=(ll)w*_w%mo;if((A=B-t)<0)A+=mo;
				if((B+=t)>=mo)B-=mo;
			}
		}
	}
	if(t){int inv=qk(n,mo-2);
		rep(i,0,n-1)a[i]=(ll)a[i]*inv%mo;
	}
}
void init(int n){
	M=-1;for(m=1;m<n*2;m<<=1)++M;
	g[M]=qk(yg,(mo-1)/m);ng[M]=qk(g[M],mo-2);
	dep(i,M-1,0){
		g[i]=(ll)g[i+1]*g[i+1]%mo;
		ng[i]=(ll)ng[i+1]*ng[i+1]%mo;
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(!t[x]){
			t[x]=++tot;p[t[x]].pb(1);
		}
		p[t[x]].pb(1);
	}
	set<pair<int,int>>s;
	rep(i,1,tot)s.insert({(int)p[i].size(),i});
	while(s.size()>1){
		int x=s.begin()->sc;s.erase(s.begin());
		int y=s.begin()->sc;s.erase(s.begin());
		int l=p[x].size()+p[y].size()-1;init(l);
		rep(i,0,m-1){
			a[i]=i<(int)p[x].size()?p[x][i]:0;
			b[i]=i<(int)p[y].size()?p[y][i]:0;
		}
		p[x].clear();ntt(a,m,0);
		p[y].clear();ntt(b,m,0);
		rep(i,0,m-1)a[i]=(ll)a[i]*b[i]%mo;
		ntt(a,m,1);
		rep(i,0,l-1)p[x].pb(a[i]);
		s.insert({l,x});
	}
	printf("%d\n",p[s.begin()->sc][n/2]);
}