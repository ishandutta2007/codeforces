#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],vis[N],jb[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		vis[i]=0;
		jb[i]=0;
	}
	for(int i=1,j=n;i<=n;++i){
		if(vis[i])continue;
		while(!vis[i]){
			vis[a[j--]]=1;
		}
		cout<<i<<' ';
		jb[j+1]=1;
	}
	for(int i=1;i<=n;++i){
		if(jb[i])continue;
		cout<<a[i]<<' ';	
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