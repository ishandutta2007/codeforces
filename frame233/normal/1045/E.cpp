#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=1005;typedef std::pair<int,int> pi;
struct vec{
	int x,y;
	inline vec operator + (const vec &o)const{return (vec){x+o.x,y+o.y};}
	inline vec operator - (const vec &o)const{return (vec){x-o.x,y-o.y};}
}a[N],b[N];int c[N],t[N],st[N],n,top;std::vector<pi> E;
inline int cross(const vec &a,const vec &b){return a.x*b.y-a.y*b.x;}
std::vector<int> gethull(int n){
	int mn=1;for(int i=2;i<=n;++i)if(a[i].x<a[mn].x||(a[i].x==a[mn].x&&a[i].y<a[mn].y))mn=i;
	for(int i=1;i<=n;++i)b[i]=a[i]-a[mn];
	int p=0;for(int i=1;i<=n;++i)if(i!=mn)t[++p]=i;
	std::sort(t+1,t+p+1,[&](int x,int y){return std::atan2(b[x].y,b[x].x)<std::atan2(b[y].y,b[y].x);});
	st[top=1]=mn;
	for(int _=1;_<=p;++_){
		int i=t[_];while(top>1&&cross(b[i]-b[st[top-1]],b[st[top]]-b[st[top-1]])>0)--top;
		st[++top]=i;
	}
	return {st+1,st+top+1};
}
inline int S(int u,int v,int w){return abs(cross(a[w]-a[u],a[v]-a[u]));}
inline bool checkin(int x,int u,int v,int w){return S(x,u,v)+S(x,u,w)+S(x,v,w)==S(u,v,w);}
void solve(int u,int v,int w){
	int col=c[u]==c[v]||c[u]==c[w]?c[u]:c[v];
	if(c[v]!=col)std::swap(u,v);
	if(c[w]!=col)std::swap(u,w);
	for(int i=1;i<=n;++i)if(c[i]!=col&&checkin(i,u,v,w)&&i!=u&&i!=v&&i!=w){E.pb({u,i}),solve(u,v,i),solve(v,w,i),solve(u,w,i);return;}
	for(int i=1;i<=n;++i)if(c[i]==col&&i!=u&&i!=v&&i!=w&&checkin(i,u,v,w))E.pb({v,i});
}
int main(){
	read(n);for(int i=1;i<=n;++i)read(a[i].x,a[i].y,c[i]);
	bool flag=1;for(int i=1;i<=n;++i)flag&=c[1]==c[i];
	if(flag){
		printf("%d\n",n-1);
		for(int i=1;i<n;++i)printf("%d %d\n",0,i);
		return 0;
	}
	std::vector<int> hull=gethull(n);
	int cnt=0;for(int i=0;i<SZ(hull);++i)cnt+=c[hull[i]]!=c[hull[(i+1)%SZ(hull)]];
	if(cnt>2)return puts("Impossible"),0;
	for(int i=0;i<SZ(hull);++i)if(c[hull[i]]==c[hull[(i+1)%SZ(hull)]])E.pb({hull[i],hull[(i+1)%SZ(hull)]});
	if(cnt==0){E.pop_back();for(int i=1;i<=n;++i)if(c[i]!=c[hull[0]]){for(int j=0;j<SZ(hull);++j)solve(i,hull[j],hull[(j+1)%SZ(hull)]);break;}}
	else{
		for(int i=0;i<SZ(hull);++i)if(c[hull[i]]!=c[hull[0]]){std::rotate(hull.begin(),hull.begin()+i,hull.end());break;}
		int fir=-1,las=-1;
		for(auto it:hull)if(c[it]!=c[hull[0]]){
			if(fir==-1)fir=it;
			else solve(hull[0],it,las);
			las=it;
		}
		for(int i=1;i<SZ(hull);++i)if(c[hull[i]]==c[hull[0]])solve(hull[i-1],hull[i],fir);
	}
	printf("%d\n",SZ(E));
	for(auto [x,y]:E)printf("%d %d\n",x-1,y-1);
	return 0;
}