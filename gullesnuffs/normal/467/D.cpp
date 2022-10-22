#include <bits/stdc++.h>

using namespace std;

map<string, int> Ind;
int wordN;
pair<int, int> r[500005];
int minR[500005];

priority_queue<pair<pair<int, int>, int> > q;
int getInd(string s){
	string t;
	for(int i=0; i < s.size(); ++i){
		if(s[i] >= 'A' && s[i] <= 'Z')
			t.push_back(s[i]+'a'-'A');
		else
			t.push_back(s[i]);
	}
	if(Ind[t])
		return Ind[t];
	Ind[t]=++wordN;
	int rn=0;
	for(int i=0; i < s.size(); ++i)
		if(t[i] == 'r')
			++rn;
	r[Ind[t]]=make_pair(-rn, -t.size());
	q.push(make_pair(make_pair(-rn, -t.size()), Ind[t]));
	return Ind[t];
}

vector<int> adj[500005];
vector<int> essay;
int in[500005];
bool vis[500005];

int main(){
	int m;
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		string s;
		cin >> s;
		essay.push_back(getInd(s));
	}
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		string a, b;
		cin >> a >> b;
		int A=getInd(a), B=getInd(b);
		adj[B].push_back(A);
	}
		while(!q.empty()){
			int cur=q.top().second;
			q.pop();
			if(vis[cur])
				continue;
			vis[cur]=1;
			for(int j=0; j < adj[cur].size(); ++j){
				int to=adj[cur][j];
				if(r[cur] > r[to]){
					r[to]=r[cur];
					q.push(make_pair(r[to], to));
				}
			}
		}
	long long ansr=0, anslen=0;
	for(int i=0; i < essay.size(); ++i){
		ansr -= r[essay[i]].first;
		anslen -= r[essay[i]].second;
	}
	printf("%I64d %I64d\n", ansr, anslen);
}