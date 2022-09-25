#include<bits/stdc++.h>
using namespace std;
#define N 2000020
typedef long long ll;
int n,a[N],b[N],tot,_a[N],_b[N];
map<int,int> id;
class Union_Set{
public:
	int f[N],s_e[N],s_v[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i,s_e[i]=0,s_v[i]=1;	
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		++s_e[fx];
		if(fx==fy)return;
		f[fy]=fx;
		s_e[fx]+=s_e[fy];
		s_v[fx]+=s_v[fy];	
	}
}S;
bool check(int lim){
	S.init(tot);
	for(int i=1;i<=n;++i){
		S.Merge(_a[i],lim>=b[i]?_b[i]:_a[i]);
	}
	for(int i=1;i<=tot;++i){
		if(S.s_e[S.getf(i)]>S.s_v[S.getf(i)])return false;	
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l=1,r=1e9+1,ans=1e9+1;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		if(!id.count(a[i]))id[a[i]]=++tot;
		_a[i]=id[a[i]];
		if(!id.count(b[i]))id[b[i]]=++tot;
		_b[i]=id[b[i]];
		l=max(l,a[i]);
	}
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=ans=mid;
		}
		else{
			l=mid+1;
		}	
	}
	cout<<(ans>1e9?-1:ans)<<'\n';
	return 0;
}