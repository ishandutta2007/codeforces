#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
#define y1 ysgh1
#define y2 ysgh2
int n,m,y1,y2,a[N],b[N];
map<int,int> jb;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>y1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++jb[a[i]];
	}
	cin>>m>>y2;
	int ans=1;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		if(jb[b[i]])ans=max(ans,2);
	}
	for(int t=1;t<=30;++t){
		map<int,int> A,B;
		for(int i=1;i<=n;++i){
			++A[a[i]%(1<<t)];
		}
		for(int i=1;i<=m;++i){
			++B[b[i]%(1<<t)];	
		}
		for(auto [x,w]:A){
			ans=max(ans,w+B[(x+(1<<t-1))%(1<<t)]);
		}
		for(auto [x,w]:B){
			ans=max(ans,w+A[(x+(1<<t-1))%(1<<t)]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}