#include<bits/stdc++.h>
using namespace std;
#define N 266
typedef long long ll;
int n,a[N],b[N],ct[N],id[N],vis[N];
vector<pair<int,int> > cd;
inline void adde(int u,int v){
	cd.emplace_back(u,v);
}
bool Solve(){
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		bool ok=false;
		if(id[a[i]])ok=true,adde(id[a[i]],i);
		else if(!a[i])ok=true;
		else if(a[i]==3&&id[1]&&id[2])ok=true,adde(id[1],i),adde(id[2],i);
		else if(a[i]==5&&id[1]&&id[4])ok=true,adde(id[1],i),adde(id[4],i);
		else if(a[i]==6&&id[2]&&id[4])ok=true,adde(id[2],i),adde(id[4],i);
		if(!ok)continue;
		if(id[a[i]])id[b[i]]=i,ct[i]=1;
		else id[a[i]]=i;
		vis[i]=1;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=0,x;j<3;++j){
			cin>>x;
			a[i]|=x<<j;	
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0,x;j<3;++j){
			cin>>x;
			b[i]|=x<<j;	
		}
		b[i]&=a[i];
	}
	id[7]=1,vis[1]=1;
	int T=n-1;
	while(T--){
		if(!Solve()){
			cout<<"Impossible\n";
			return 0;
		}
	}
	cout<<"Possible\n";
	for(int i=1;i<=n;++i){
		cout<<ct[i]<<' ';
	}
	cout<<'\n';
	cout<<cd.size()<<'\n';
	for(auto [x,y]:cd){
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}