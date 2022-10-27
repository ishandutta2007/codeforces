#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

vector<int> g[250005];
bool vis[250005], leaf[250005];
int p[250005], d[250005];

void dfs(int v){
	vis[v] = true;
	leaf[v] = true;
	for(auto u : g[v]){
		if(!vis[u]){
			d[u] = d[v] + 1;
			p[u] = v;
			leaf[v] = false;
			dfs(u);
		}
	}
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, u, v, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    d[1] = 1;
    p[1] = 0;
    dfs(1);
    int ind = 1;
    for(int i = 1; i <= n; i++){
    	if(d[i] > d[ind])ind = i;
    }
    int req = (n/k) + (n%k != 0);
    if(d[ind] >= req){
    	cout<<"PATH"<<endl;
    	cout<<d[ind]<<endl;
    	while(ind != 0){
    		cout<<ind<<" ";
    		ind = p[ind];
    	}
    }else{
    	cout<<"CYCLES"<<endl;
    	for(int i = 1; i <= n && k > 0; i++){
    		if(!leaf[i])continue;
    		k--;
    		int x = -1, y = -1;
    		for(auto u : g[i]){
    			if(u == p[i])continue;
    			if(x == -1)x = u;
    			else if(y == -1)y = u;
    			else break;
    		}
    		if(d[x] < d[y])swap(x, y);
    		if((d[i] - d[x] + 1)%3){
    			cout<<d[i] - d[x] + 1<<endl;
    			int v = i;
    			while(v != p[x]){
    				cout<<v<<" ";
    				v = p[v];
    			}
    		}else if((d[i] - d[y] + 1)%3){
    			cout<<d[i] - d[y] + 1<<endl;
    			int v = i;
    			while(v != p[y]){
    				cout<<v<<" ";
    				v = p[v];
    			}
    		}else{
    			cout<<d[x] - d[y] + 2<<endl;
    			cout<<i<<" ";
    			int v = x;
    			while(v != p[y]){
    				cout<<v<<" ";
    				v = p[v];
    			}
    		}
    		cout<<endl;
    	}
    }
}