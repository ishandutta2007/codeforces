//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[100000+10];
int n,m;
int OK=0;
int dp[100000+10][2],las[100000+10][2],s;
int v[100000+10],reachable[100000+10];vector<int> into[100000+10];
vector<int> each2[100000+10];
void dfs(int now)
{
	reachable[now]=true;
	v[now]=1;
	for(auto it:each[now]){
		if(!v[it]){
			dfs(it);
		}
	}
}
int v2[100000+10][2];
void dfs2(int now,int color){
	v2[now][color]=1;
	dp[now][color]=1;
	color^=1;
	for(auto it:into[now]){
		if(!v2[it][color]){
			las[it][color]=now;
			dfs2(it,color);
		}
	}
} 
int degree[100000+10];
void My_sort(){
	queue<int> Q;
	int now=0;
	int Need=0;
	rep(i,n) if(reachable[i+1]) Need++;
	rep(i,n){
		if(reachable[i+1])
		for(auto it:each2[i+1]){
			if(reachable[it])
			degree[it]++;
		}
	}
	rep(i,n) if(reachable[i+1]) if(!degree[i+1]) Q.push(i+1);
	while(!Q.empty()){
		now++;
		int is=Q.front();
		Q.pop();
		for(auto it:each2[is]){
			degree[it]--;
			if(!degree[it]) Q.push(it);
		} 
	}
	if(now!=Need) OK=1;
}
int main(){
	cin>>n>>m;
	rep(i,n){
		int li;
		cin>>li;
		rep(j,li){
			int ai;
			cin>>ai;
			each[i+1].PB(ai);
			into[ai].PB(i+1);
		}
	}
	cin>>s;
	dfs(s);
	rb(i,1,n)
		if(reachable[i])
		for(auto it:each[i])
			if(reachable[it]){
				each2[i].PB(it);
			}
				
	My_sort();
	rb(i,1,n){
		if(each[i].empty()){
			las[i][1]=-1;
			dfs2(i,1);
		}
	}
	if(dp[s][0]){
		cout<<"Win"<<endl;
		int now=s;
		int color=0;
		while(now!=-1){
			cout<<now<<" ";
			now=las[now][color];
			color^=1;
		}
	}
	else{
		if(OK){
			puts("Draw");
		}
		else{
			puts("Lose");
		}
	}
	return 0;
}