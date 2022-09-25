#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m;
class Union_Set{
public:
	vector<int> f;
	int sz;
	void init(int n){
		f.resize(n+1);
		for(int i=1;i<=n;++i)f[i]=i;
		sz=n;
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
		--sz;
	}
};
int x[N],y[N],w[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i]>>w[i];
	}
	int ans=0,ban=0;
	for(int i=30;i>=0;--i){
		Union_Set S;
		S.init(n);
		ban|=1<<i;
		for(int j=1;j<=m;++j){
			if(!(ban&w[j])){
				S.Merge(x[j],y[j]);
			}
		}
		if(S.sz>1){
			ans|=1<<i;
			ban^=1<<i;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}