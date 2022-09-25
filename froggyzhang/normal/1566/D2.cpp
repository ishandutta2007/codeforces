#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 303
typedef long long ll;
int n,a[N],m,b[N],s[M][M],t[N],_a[N];
int c[M][M];
vector<pair<int,int> > pos[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		b[i]=a[i];
		pos[i].clear();
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;++i){
		t[i]=b[i];
	}
	int len=unique(t+1,t+n*m+1)-t-1;
	for(int i=1;i<=n*m;++i){
		a[i]=lower_bound(t+1,t+len+1,a[i])-t;
		b[i]=lower_bound(t+1,t+len+1,b[i])-t;	
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j){
			s[i][j]=0;
			c[i][j]=b[(i-1)*m+j];
			pos[c[i][j]].emplace_back(i,j);	
		}
	}
	for(int i=1;i<=len;++i){
		reverse(pos[i].begin(),pos[i].end());	
	}
	int ans=0;
	for(int i=1;i<=n*m;++i){
		auto [x,y]=pos[a[i]].back();
		pos[a[i]].pop_back();
		ans+=s[x][y];
		for(int k=y;k<=m;++k){
			++s[x][k];	
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}