#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int size[300001],ans[300001];
vector<int>child[300001];
int par[300001];
int n,p,q;
void cal_size(int id){
	size[id]=1;
	for(int i=0; i<child[id].size() ;i++){
		cal_size(child[id][i]);
		size[id]+=size[child[id][i]];
	}
}
void cal_ans(int id){
	int maxi=0,maxnum;
	for(int i=0; i<child[id].size() ;i++){
		cal_ans(child[id][i]);
		if(maxi<size[child[id][i]]){
			maxi=size[child[id][i]];
			maxnum=child[id][i];
		}
	}
	if(maxi*2<=size[id]) ans[id]=id;
	else{
		for(int i=ans[maxnum]; i!=id ;i=par[i]){
			if(size[id]-size[i]<=size[id]/2){
				ans[id]=i;
				break;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=2; i<=n ;i++){
		cin >> p;
		child[p].push_back(i);
		par[i]=p;
	}
	cal_size(1);cal_ans(1);
	for(int i=1; i<=q ;i++){
		cin >> p;
		cout << ans[p] << endl;
	}
}