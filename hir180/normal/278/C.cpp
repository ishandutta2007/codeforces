#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int par[105];
int ran[105];
void init(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x){
	if(par[x] == x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x == y) return ;
	if(ran[x]<=ran[y]){
		par[x]=par[y];
	}else{
		par[y]=par[x];
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	vector<int>vec[105];
	bool all=true;
	for(int i=1;i<=n;i++){
		int e;
		scanf("%d",&e);
		if(e) all=false;
		for(int j=0;j<e;j++){
			int ep;
			cin >> ep;
			vec[ep].pb(i);
		}
	}
	init(n);
	for(int i=1;i<=m;i++){
		if(vec[i].size()>=2){
		for(int j=0;j<vec[i].size();j++){
			if(j==vec[i].size()-1){
				unite(vec[i][j],vec[i][0]);
			}
			else{
				unite(vec[i][j],vec[i][j+1]);
			}
		}
		}
	}
	int cou=-1;
	bool used[105]={};
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			cou++;
			for(int j=1;j<=n;j++){
				if(same(i,j)){
					used[j]=true;
				}
			}
		}
	}
	printf("%d\n",all?1+cou:cou);
	return 0;
}