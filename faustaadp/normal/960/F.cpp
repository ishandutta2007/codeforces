#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef pair<int,int> pii;

set<pii> arr[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m,u,v,w,ans=-1;
	cin >> n >> m;
	for(int i=1;i<=n;i++)arr[i].insert({-1,0});
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		auto it=arr[u].lower_bound({w,MAXN+5});
		--it;
		int numedge=(*it).second+1;
		//ingin masukkan {w,numedge}
		it=arr[v].lower_bound({w,MAXN+5});
		--it;
		if(numedge<=(*it).second)continue;
		++it;
		while(it!=arr[v].end() && numedge>=(*it).second){
			auto baru=it;
			++it;
			arr[v].erase(baru);
		}
		arr[v].insert({w,numedge});
		ans=max(ans,numedge);
	}
	cout << ans << endl;
	return 0;
}