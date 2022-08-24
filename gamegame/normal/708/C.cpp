#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
#define ns 400001
int size[ns];
vector<int>child[ns];
vector<int>link[ns];
bool intree[ns];
int sm1[ns],sm2[ns];
bool ans[ns];
int par[ns];
void build(int id){
	intree[id]=true;
	size[id]=1;
	for(int i=0; i<link[id].size() ;i++){
		if(!intree[link[id][i]]){
			child[id].push_back(link[id][i]);
			par[link[id][i]]=id;
			build(link[id][i]);
			size[id]+=size[link[id][i]];
			if(size[sm2[id]]<size[link[id][i]] && size[link[id][i]]<=m){
				sm2[id]=link[id][i];
				if(size[sm1[id]]<size[sm2[id]]) swap(sm1[id],sm2[id]);
			}
			else if(size[sm2[id]]<size[sm1[link[id][i]]]) sm2[id]=sm1[link[id][i]];
			if(size[sm1[id]]<size[sm2[id]]) swap(sm1[id],sm2[id]);
		}
	}
}
void cal(int id,int path,int other){
	ans[id]=true;
	for(int i=0; i<child[id].size() ;i++){
		if(size[child[id][i]]<=m)continue;
		if(size[child[id][i]]-size[sm1[child[id][i]]]>m) ans[id]=false;
		break;
	}
	if(sm1[par[id]]==sm1[id] || sm1[par[id]]==id) other=max(other,size[sm2[par[id]]]);
	else other=max(other,size[sm1[par[id]]]);
	if(size[1]-size[id]<=m) path=size[1]-size[id];
	else{
		if(size[1]-other-size[id]>m && size[1]-path-size[id]>m) ans[id]=false;
	}
	for(int i=0; i<child[id].size() ;i++){
		cal(child[id][i],path,other);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	m=n/2;
	int p,q;
	for(int i=1; i<n ;i++){
		cin >> p >> q;
		link[p].push_back(q);
		link[q].push_back(p);
	}
	build(1);
	cal(1,0,0);
	for(int i=1; i<=n ;i++){
		cout << ans[i] << ' ';
	}
}