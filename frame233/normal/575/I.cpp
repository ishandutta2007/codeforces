#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=5005,NN=10005,M=100005;
struct node{int x,y,z;};
int ans[M],O[M],D[M],X[M],Y[M],L[M];
namespace DS{
	int c[NN];
	void add(int x,int C){for(;x;x-=lowbit(x))c[x]+=C;}
	int ask(int x){int ans=0;for(;x<NN;x+=lowbit(x))ans+=c[x];return ans;}
}
int c[N][NN];
void add(int x,int y,int C){for(;x;x-=lowbit(x))for(int i=y;i;i-=lowbit(i))c[x][i]+=C;}
int ask(int x,int y){int ans=0;for(;x<N;x+=lowbit(x))for(int i=y;i<NN;i+=lowbit(i))ans+=c[x][i];return ans;}
void solve(const std::vector<node> &Q){
	memset(DS::c,0,sizeof(DS::c));for(auto [x,y,z]:Q){if(z<0)ans[-z]+=DS::ask(std::min(x+y,NN-1));else DS::add(std::min(x+y+z,NN-1),1);}
	memset(c,0,sizeof(c));for(auto [x,y,z]:Q){if(z<0)ans[-z]+=ask(x,std::min(x+y,NN-1));else add(x-1,std::min(x+y+z,NN-1),-1);}
	memset(c,0,sizeof(c));for(auto [x,y,z]:Q){if(z<0)ans[-z]+=ask(y,std::min(x+y,NN-1));else add(y-1,std::min(x+y+z,NN-1),-1);}
	memset(c,0,sizeof(c));for(auto [x,y,z]:Q){if(z<0)ans[-z]+=ask(x,y);else add(x-1,y-1,1);}
}
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=q;++i){
		read(O[i]);
		if(O[i]==1)read(D[i],X[i],Y[i],L[i]),--D[i];
		else read(X[i],Y[i]);
	}
	for(int d=0;d<4;++d){
		std::vector<node> Q;
		for(int i=1;i<=q;++i){
			int x=X[i],y=Y[i];if(d&1)y=n-y+1;if(d&2)x=n-x+1;
			if(O[i]==2)Q.pb({x,y,-i});
			else if(D[i]==d)Q.pb({x,y,L[i]});
		}
		solve(Q);
	}
	for(int i=1;i<=q;++i)if(O[i]==2)printf("%d\n",ans[i]);
	return 0;
}