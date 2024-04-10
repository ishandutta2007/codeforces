#include<bits/stdc++.h>
namespace orzwn{
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=75005;int BB;typedef long long ll;typedef std::pair<int,int> pi;const double eps=0.01,EPS=0.1;
double x1[N],y1[N],x2[N],y2[N];int n,n1,n2,tar;bool used1[N],used2[N];
inline bool cmp(double a,double b){return abs(a-b)<=eps;}
inline bool CMP(double a,double b){return abs(a-b)<=EPS;}
inline double sqr(double x){return x*x;}
inline double getdis1(int x,int y){return sqrt(sqr(x1[x]-x1[y])+sqr(y1[x]-y1[y]));}
inline double getdis2(int x,int y){return sqrt(sqr(x2[x]-x2[y])+sqr(y2[x]-y2[y]));}
struct vec{double x,y;inline bool operator < (const vec &o)const{return CMP(x,o.x)?CMP(y,o.y)?0:y<o.y:x<o.x;}};
std::map<vec,int> mp;
struct node{
	double len;int i,j;
	inline bool operator < (const node &o)const{return len<o.len;}
}a[1000005];
void solve(int a,int b,int c,int d){
	double t=atan2(y1[b]-y1[a],x1[b]-x1[a])-atan2(y2[d]-y2[c],x2[d]-x2[c]),S=sin(t),C=cos(t);
	auto get=[&](double x,double y)->vec{
		x-=x2[c],y-=y2[c];
		return {x*C-y*S+x1[a],x*S+y*C+y1[a]};
	};
	std::vector<pi> ans;ans.pb({a,c}),ans.pb({b,d}),used1[a]=used1[b]=1,used2[c]=used2[d]=1;
	for(int i=1;i<=n2;++i)if(i!=c&&i!=d){
		vec tmp=get(x2[i],y2[i]);auto it=mp.find((vec){tmp.x,tmp.y});
		if(it!=mp.end()&&!used1[it->second])used1[it->second]=used2[i]=1,ans.pb({it->second,i});
		if(i>=100&&SZ(ans)<=i/3)break;
	}
	if(SZ(ans)<tar){
		for(const auto &it:ans)used1[it.first]=used2[it.second]=0;
		return;
	}
	std::vector<int> v1,v2;
	for(int i=1;i<=n1;++i)if(!used1[i])v1.pb(i);
	for(int i=1;i<=n2;++i)if(!used2[i])v2.pb(i);
	while(SZ(ans)<n)ans.pb({v1.back(),v2.back()}),v1.pop_back(),v2.pop_back();
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
	exit(0);
}
int main(){
	read(n,n1),tar=(n*9+9)/10;
	for(int i=1;i<=n1;++i)scanf("%lf%lf",&x1[i],&y1[i]),mp[{x1[i],y1[i]}]=i;
	read(n2);for(int i=1;i<=n2;++i)scanf("%lf%lf",&x2[i],&y2[i]);
	int pos=0;
	for(int t=0;t<1e6;++t){
		int x,y;do{x=rnd()%n1+1,y=rnd()%n1+1;}while(x==y);
		a[++pos]={getdis1(x,y),x,y};
	}
	std::sort(a+1,a+pos+1);
	while(true){
		int i=rnd()%n2+1,j=rnd()%n2+1;while(i==j)i=rnd()%n2+1,j=rnd()%n2+1;
		double cur=getdis2(i,j);
		int p=std::lower_bound(a+1,a+pos+1,(node){cur-eps,i,j})-a;
		for(int k=p;k<=pos;++k){
			if(abs(cur-a[k].len)<=eps)solve(a[k].i,a[k].j,i,j),solve(a[k].i,a[k].j,j,i);
			else break;
		}
	}
	return 0;
}
}
int main(){return orzwn::main();}