#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> al[1005];
bool bad[1005];
int E[3];

bool dfs(int i,int p,int d){
	if (bad[i]) return false;
	E[d]=i;
	if (d==2) return true;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		if (dfs(it,i,d+1)) return true;
	}
	return false;
}

int main(){
	cin>>n;
	
	int a,b;
	for (int x=1;x<n;x++){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	int curr=1;
	while (true){
		if (dfs(curr,-1,0)){
			cout<<"? "<<E[0]<<" "<<E[2]<<endl;
			cin>>curr;
			for (int x=0;x<3;x++) if (E[x]!=curr) bad[E[x]]=true;
		}
		else{
			vector<int> temp;
			int lca;
			for (auto &it:al[curr]){
				if (!bad[it]) temp.push_back(it);
			}
			
			while (temp.size()>1){
				cout<<"? "<<temp[temp.size()-1]<<" "<<temp[temp.size()-2]<<endl;
				cin>>lca;
				if (lca!=curr){
					cout<<"! "<<lca<<endl;
					return 0;
				}
				temp.pop_back();
				temp.pop_back();
			}
			if (temp.size()==1){
				cout<<"? "<<temp[0]<<" "<<curr<<endl;
				cin>>curr;
			}
			
			cout<<"! "<<curr<<endl;
			return 0;
		}
	}
}