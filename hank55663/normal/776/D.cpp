#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
vector<int> door[N];
vector<int> v[N];
int r[N];
int f[N];
void build(int n){
	for(int i=0;i<N;i++)
	f[i]=i;
	for(int i=0;i<N;i++)
	v[i].clear();
	for(int i=0;i<n;i++)
	{
		int a=door[i][0],b=door[i][1];
		if(r[i]==0){
			v[a].pb(100000+b);
			v[b].pb(100000+a);
			v[100000+b].pb(a);
			v[100000+a].pb(b);
		}
		else{
			v[a].pb(b);
			v[b].pb(a);
			v[100000+a].pb(100000+b);
			v[100000+b].pb(100000+a); 
		}
	}
}
int instk[N],visit[N];
stack<int> s; 
int Find(int n){
	if(f[n]!=n)
	return f[n]=Find(f[n]);
	return n;
}
void dfs(int n){
	s.push(n);
	visit[n]=1;
	instk[n]=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it]){
			dfs(*it);
		}
		else{
			int fit=Find(*it);
			if(instk[fit])
			while(1){
				int fs=Find(s.top());
				if(fs==fit)
				break;
				f[fs]=fit;
				instk[s.top()]=0;
				s.pop();
			}
		}
	}
	if(s.top()==n)
	{
		s.pop();
		instk[n]=0;
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%d",&r[i]);
	memset(visit,0,sizeof(visit));
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			a--;
			door[a].pb(i);
		}
	}
	build(n);
	for(int i=0;i<N;i++)
	if(!visit[i])
	dfs(i);
	for(int i=0;i<m;i++){
		if(Find(i)==Find(100000+i)){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}