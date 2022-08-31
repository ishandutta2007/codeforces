#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<120> duh;
const ll mod=1e9+7;
#define fi first
#define se second
int n,k;
int f[120][120];
int g[120][6];
int h[6][6][6][6][6];
vector<pair<pair<duh,int>,vector<int> > >god[2];
duh zero;
duh tmppp;
int way;
duh d;
vector<int>t;
void dfs(int id){
	for(auto cur:t){
		if(!d[f[id][cur]]){
			d[f[id][cur]]=true;
			dfs(f[id][cur]);
		}
	}
}
duh dog(vector<int>v,int gg){
	v.push_back(gg);t=v;
	d=zero;
	dfs(0);
	return d;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	int p[6]={0,1,2,3,4,5};
	for(int i=0; i<120 ;i++){
		for(int j=1; j<=5 ;j++) g[i][j]=p[j];
		h[p[1]][p[2]][p[3]][p[4]][p[5]]=i;
		next_permutation(p+1,p+6);
	}
	for(int i=0; i<120 ;i++){
		for(int j=0; j<120 ;j++){
			f[i][j]=h[g[j][g[i][1]]][g[j][g[i][2]]][g[j][g[i][3]]][g[j][g[i][4]]][g[j][g[i][5]]];
		}
	}
	zero[0]=1;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=k ;j++){
			cin >> p[j];
		}
		for(int j=k+1; j<=5 ;j++) p[j]=j;
		int id=h[p[1]][p[2]][p[3]][p[4]][p[5]];
		int cr=i&1;int pv=cr^1;
		vector<int>ff;
		god[pv].push_back({{zero,1},ff});
		god[cr].clear();
		for(auto cur:god[pv]){
			duh tmp=dog(cur.se,id);
			if(tmp!=cur.fi.fi) cur.fi.fi=tmp,cur.se.push_back(id);
			if(!god[cr].empty() && god[cr].back().fi.fi==tmp) god[cr].back().fi.se+=cur.fi.se;
			else god[cr].push_back(cur);
		}
		for(auto cur:god[cr]){
			ans+=cur.fi.fi.count()*cur.fi.se;
		}
	}
	cout << ans << endl;
}