#include<iostream>
#include<queue>
using namespace std;
int ptr1=0,ptr2=0,n,m,p,q;
int vis[100001],a[100001];
bool isson[100001];
vector<int>link[100001],child[100001];
vector<int>ans;
bool ok=true;
void build_tree(int id){
	vis[id]=1;
	for(int i=0; i<link[id].size() ;i++){
		if(!vis[link[id][i]]){
			child[id].push_back(link[id][i]);
			build_tree(link[id][i]);
		}
	}
}
void calculate(int id){
	for(int i=0; i<child[id].size() ;i++){
		if(a[child[id][i]]==child[id][i]){
			ans.push_back(child[id][i]);
		}
		else if(a[child[id][i]]!=a[id]){
			ok=false;
		}
		calculate(child[id][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<m ;i++){
		cin >> p >> q;
		child[p].push_back(q);
		isson[q]=true;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		if(!isson[i]){
			if(a[i]!=i){
				ok=false;break;
			}
			ans.push_back(i);
			calculate(i);
		}
	}
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(int i=ans.size()-1; i>=0 ;i--){
		cout << ans[i] << endl;
	}
}