#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll w[100001];
vector<int>a,b;
vector<int>ax,ay;
vector<ll>az;
int main(){
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;ll z;cin >> u >> v >> z;
		w[u]+=z;w[v]-=z;
	}
	for(int i=1; i<=n ;i++){
		if(w[i]>0) a.push_back(i);
		else b.push_back(i);
	}
	while(!a.empty() && !b.empty()){
		if(w[a.back()]+w[b.back()]>0){
			w[a.back()]+=w[b.back()];
			ax.push_back(a.back());
			ay.push_back(b.back());
			az.push_back(-w[b.back()]);
			b.pop_back();
		}
		else{
			w[b.back()]+=w[a.back()];
			ax.push_back(a.back());
			ay.push_back(b.back());
			az.push_back(w[a.back()]);
			a.pop_back();
		}
		if(az.back()==0){
			ax.pop_back();ay.pop_back();az.pop_back();
		}
	}
	cout << ax.size() << endl;
	for(int i=0; i<ax.size() ;i++){
		
		cout << ax[i] << ' ' << ay[i] << ' ' << az[i] << '\n';
	}
}