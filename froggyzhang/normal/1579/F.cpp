#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,d,a[N],vis[N];
void Solve(){
	cin>>n>>d;
	for(int i=0;i<n;++i){
		cin>>a[i];
		vis[i]=0;
	}
	int A=0;
	for(int i=0;i<n;++i){
		if(vis[i])continue;
		vector<int> ans;
		for(int u=i;!vis[u];u=(u+d)%n){
			vis[u]=1;
			ans.push_back(a[u]);
		}
		bool zero=false;
		for(int j=0;j<(int)ans.size();++j){
			if(!ans[j]){zero=true;rotate(ans.begin(),ans.begin()+j,ans.end());break;}
		}
		if(!zero){
			cout<<-1<<'\n';
			return;
		}
		int now=0;
		for(auto x:ans){
			if(!x)now=0;
			else ++now;
			A=max(A,now);	
		}
	}
	cout<<A<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}