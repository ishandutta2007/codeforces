#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 2000
char s[maxn][maxn];
int f[maxn], p[maxn], d[maxn];
int getf(int u){
	return u == f[u] ? u : f[u] = getf(f[u]);
}
void no(){
	cout << "No";
	exit(0);
}
vector<int> G[maxn];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1) cin >> s[i];
	for(int i = 0; i < n + m; i += 1) f[i] = i;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			if(s[i][j] == '='){
				int u = getf(i), v = getf(n + j);
				f[u] = v;
			}
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			if(s[i][j] != '='){
				int u = getf(i), v = getf(n + j);
				if(s[i][j] == '<'){
					G[u].push_back(v);
					d[v] += 1;
				}
				else{
					G[v].push_back(u);
					d[u] += 1;
				}
			}
	queue<int> q;
	for(int i = 0; i < n + m; i += 1) if(getf(i) == i and not d[i]){
		q.push(i);
		p[i] = 1;
	}
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v : G[u]) if(not -- d[v]){
			q.push(v);
			p[v] = p[u] + 1;
		}
	}
	for(int i = 0; i < n + m; i += 1) if(not(p[i] = p[getf(i)])) no();
	cout << "Yes" << endl;
	for(int i = 0; i < n; i += 1) cout << p[i] << " ";
	cout << endl;
	for(int i = 0; i < m; i += 1) cout << p[i + n] << " ";
}