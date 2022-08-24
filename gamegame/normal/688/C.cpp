#include<iostream>
#include<vector>
using namespace std;
int ans[100001];
vector<int>a[100001];
vector<int>ans1,ans2;
bool ok=true;
int n,m,p,q;
void dfs(int id){
	for(int i=0; i<a[id].size() ;i++){
		if(ans[a[id][i]]==2){
			ans[a[id][i]]=1-ans[id];
			if(ans[a[id][i]]==0){
				ans1.push_back(a[id][i]);
			}
			else{
				ans2.push_back(a[id][i]);
			}
			dfs(a[id][i]);
		}
		else if(ans[a[id][i]]==ans[id]){
			ok=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) ans[i]=2;
	for(int i=1; i<=m ;i++){
		cin >> p >> q;
		a[p].push_back(q);
		a[q].push_back(p);
	}
	for(int i=1; i<=n ;i++){
		if(ans[i]==2){
			ans[i]=0;
			ans1.push_back(i);
			dfs(i);
		}
	}
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	cout << ans1.size() << endl;
	for(int i=0; i<ans1.size() ;i++) cout << ans1[i] << ' ';
	cout << endl;	
	cout << ans2.size() << endl;
	for(int i=0; i<ans2.size() ;i++) cout << ans2[i] << ' ';
	cout << endl;
	
}