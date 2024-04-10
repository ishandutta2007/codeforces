#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,a[N],b[N],ans[N];
struct Data{
	int x,y,id;	
}c[N<<1];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		ans[i]=-1;
	}
	m=0;
	for(int i=1;i<=n;++i){
		c[++m]={a[i],b[i],i};
		c[++m]={b[i],a[i],i};	
	}
	sort(c+1,c+m+1,[&](Data a,Data b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	pair<int,int> mn=make_pair(2e9,-1);
	for(int i=1,j;i<=m;i=j){
		j=i;
		while(j<=m&&c[i].x==c[j].x)++j;
		for(int k=i;k<j;++k){
			if(c[k].y>mn.first){
				ans[c[k].id]=mn.second;
			}
		}
		for(int k=i;k<j;++k)
		mn=min(mn,make_pair(c[k].y,c[k].id));
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<' ';	
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}