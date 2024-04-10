#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n;
vector<int> al[100005];

vector<int> parity;
bool used[100005];

void dfs(int i,int p,int w){
	if (al[i].size()==1 && p!=-1) parity.push_back(w);

	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i,w+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n;
	
	int a,b;
	for (int x=1;x<n;x++){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	for (int x=1;x<=n;x++){
		if (al[x].size()==1){
			dfs(x,-1,0);
			break;
		}
	}
	
	int mini=1;
	
	for (int x=0;x<parity.size();x++){
		if (parity[x]%2!=0) mini=3;
	}
	
	int maxi=n-1;
	for (int x=1;x<=n;x++) if (al[x].size()==1){
		if (used[al[x][0]]) maxi--;
		used[al[x][0]]=true;
	}
	
	cout<<mini<<" "<<maxi<<endl;
}