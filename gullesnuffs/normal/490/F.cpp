#include <bits/stdc++.h>

using namespace std;

vector<int> adj[6005];
int n;
int r[6005];
set<int> Rs;
map<int, int> RMap;
short Min[6005][6005];
short Max[6005][6005];
int deg[6005];
bool done[6005];
int Mina[6006];
int Maxa[6005];

/*void fix(int i, int val, int &b1, int &bVal1, int &b2, int &bVal2, bool less){
	if((val < bVal1 && less) || (val > bVal1 && !less)){
		bVal2=bVal1;
		b2=b1;
		b1=i;
		bVal1=val;
	}
	else if((val < bVal2 && less) || (val > bVal2 && !less)){
		bVal2=val;
		b2=i;
	}
}*/

int main(){
	int ans=0;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", r+i);
		Rs.insert(r[i]);
	}
	int rN=0;
	for(auto it=Rs.begin(); it != Rs.end(); ++it){
		RMap[*it]=rN++;
	}
	for(int i=0; i < n; ++i)
		r[i]=RMap[r[i]]+1;
	for(int i=0; i < n-1; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		++deg[a];
		++deg[b];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	for(int i=0; i < n; ++i)
		if(deg[i] == 1)
			q.push(i);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(done[cur])
			continue;
		done[cur]=1;
		for(int sp=0; sp < rN+3; ++sp){
			int bMin1=-1;
			int bMinVal1=0;
			int bMin2=-1;
			int bMinVal2=0;
			int bMax1=-1;
			int bMaxVal1=0;
			int bMax2=-1;
			int bMaxVal2=0;
			for(int i=0; i < adj[cur].size(); ++i){
				int node=adj[cur][i];
				if(done[node]){
					int mx=Max[node][sp];
					int mn=Min[node][sp];
					/*fix(i, mn, bMin1, bMinVal1, bMin2, bMinVal2, 0);
					fix(i, mx, bMax1, bMaxVal1, bMax2, bMaxVal2, 0);*/
					if(mn > bMinVal1){
						bMin2=bMin1;
						bMinVal2=bMinVal1;
						bMin1=i;
						bMinVal1=mn;
					}
					else if(mn > bMinVal2){
						bMinVal2=mn;
						bMin2=i;
					}
					if(mx > bMaxVal1){
						bMax2=bMax1;
						bMaxVal2=bMaxVal1;
						bMax1=i;
						bMaxVal1=mx;
					}
					else if(mx > bMaxVal2){
						bMaxVal2=mx;
						bMax2=i;
					}
					
				}
			}
			int val;
			if(bMin1 == bMax1){
				val=max(bMinVal1+bMaxVal2, bMinVal2+bMaxVal1);
			}
			else
				val=bMinVal1+bMaxVal1;
			if(r[cur] == sp)
				++val;
			ans=max(val, ans);
			Mina[sp]=bMinVal1;
			Maxa[sp]=bMaxVal1;
		}
		for(int sp=0; sp < rN+3; ++sp){
			int bMin1=-1;
			int bMinVal1=0;
			int bMin2=-1;
			int bMinVal2=0;
			int bMax1=-1;
			int bMaxVal1=0;
			int bMax2=-1;
			int bMaxVal2=0;
			for(int i=0; i < adj[cur].size(); ++i){
				int node=adj[cur][i];
				if(done[node]){
					int mx=Max[node][sp+1];
					int mn=Min[node][sp];
					if(mn > bMinVal1){
						bMin2=bMin1;
						bMinVal2=bMinVal1;
						bMin1=i;
						bMinVal1=mn;
					}
					else if(mn > bMinVal2){
						bMinVal2=mn;
						bMin2=i;
					}
					if(mx > bMaxVal1){
						bMax2=bMax1;
						bMaxVal2=bMaxVal1;
						bMax1=i;
						bMaxVal1=mx;
					}
					else if(mx > bMaxVal2){
						bMaxVal2=mx;
						bMax2=i;
					}
					
				}
			}
			int val;
			if(bMin1 == bMax1){
				val=max(bMinVal1+bMaxVal2, bMinVal2+bMaxVal1);
			}
			else
				val=bMinVal1+bMaxVal1;
			ans=max(val, ans);
		}
		for(int sp=0; sp < rN+3; ++sp){
			if(sp < r[cur]){
				Min[cur][sp]=max(Mina[sp], Mina[r[cur]]+1);
			}
			else
				Min[cur][sp]=Mina[sp];
			if(sp > r[cur]){
				Max[cur][sp]=max(Maxa[sp], Maxa[r[cur]]+1);
			}
			else
				Max[cur][sp]=Maxa[sp];
		}
		for(int i=0; i < adj[cur].size(); ++i){
			int node=adj[cur][i];
			--deg[node];
			if(deg[node] <= 1)
				q.push(node);
		}
	}
	printf("%d\n", ans);
}