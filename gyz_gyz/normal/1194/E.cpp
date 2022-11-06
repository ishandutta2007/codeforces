#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e4+10;
const int mo=1e9+7;
struct QS{int x,yl,yr;
friend bool operator <(const QS&a,const QS&b){return a.x<b.x;}
};
struct FC{int x,y,id;
friend bool operator <(const FC&a,const FC&b){return a.x<b.x;}
};
int a[N];bool v[N];
inline int q(int x){int r=0;
	for(;x;x-=x&(-x))r+=a[x];return r;
}
inline void f(int x,int y){
	for(;x<N;x+=x&(-x))a[x]+=y;
}
int main(){int n;
	scanf("%d",&n);
	vector<QS>qs;vector<FC>fc1,fc2;
	rep(i,1,n){int xl,xr,yl,yr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		xl+=5001;xr+=5001;yl+=5001;yr+=5001;
		if(xl==xr){
			if(yl>yr)swap(yl,yr);
			qs.pb({xl,yl,yr});
		}else{
			if(xl>xr)swap(xl,xr);
			fc1.pb({xl,yl,i});fc2.pb({xr,yl,i});
		}
	}ll ans=0;
	sort(qs.begin(),qs.end());
	sort(fc1.begin(),fc1.end());
	sort(fc2.begin(),fc2.end());
	auto x=fc1.begin(),y=fc2.begin();
	for(auto i=qs.begin();i!=qs.end();++i){
		for(;x!=fc1.end()&&x->x<=i->x;++x){
			v[x->id]=1;f(x->y,1);
		}
		for(;y!=fc2.end()&&y->x<i->x;++y){
			v[y->id]=0;f(y->y,-1);
		}auto z=y;
		for(auto j=i+1;j!=qs.end();++j){
			int l=max(i->yl,j->yl),r=min(i->yr,j->yr);
			if(l>r)continue;
			for(;z!=fc2.end()&&z->x<j->x;++z)if(v[z->id])f(z->y,-1);
			ll s=q(r)-q(l-1);ans+=s*(s-1)/2;
		}
		while(z--!=y)if(v[z->id])f(z->y,1);
	}
	printf("%lld\n",ans);
}