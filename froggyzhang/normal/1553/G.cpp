#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mx=1e6+1;
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
int n,Q,a[N],p[N>>2],pn,vis[N];
bitset<N> ntp;
vector<int> fac[N];
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}	
}
class Union_Set{
public:
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;	
	}
}S;
set<pair<int,int> > s;
int main(){
	n=read(),Q=read();
	init(mx);
	for(int i=1;i<=n;++i){
		a[i]=read();
		vis[a[i]]=1;
	}
	S.init(mx);
	for(int i=1;i<=pn;++i){
		for(int j=p[i];j<=mx;j+=p[i]){
			fac[j].push_back(p[i]);
			if(vis[j])S.Merge(j,p[i]);
		}
	}
	for(int i=1;i<=n;++i){
		vector<int> A(1,S.getf(a[i]));
		for(auto x:fac[a[i]+1]){
			A.push_back(S.getf(x));
		}
		sort(A.begin(),A.end());
		A.erase(unique(A.begin(),A.end()),A.end());
		for(int j=0;j<(int)A.size();++j){
			for(int k=j+1;k<(int)A.size();++k){
				s.insert(make_pair(A[j],A[k]));
			}
		}
	}
	while(Q--){
		int x=read(),y=read();
		int fx=S.getf(a[x]),fy=S.getf(a[y]);
		if(fx==fy){puts("0");continue;}
		if(fx>fy)swap(fx,fy);
		if(s.count(make_pair(fx,fy))){puts("1");continue;}
		puts("2");
	}
	return 0;
}