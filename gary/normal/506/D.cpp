/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,tot=0;
vector<int> belong_set[100000+10],each[100000+10];
vector<mp> color[100000+10];
int ok[100000+10];
void dfs(int now){
	ok[now]=1;
	belong_set[now].PB(tot);
	for(auto it:each[now]){
		if(!ok[it]){
			dfs(it);
		}
	}
}
void process(int col){
	queue<int> q;
	for(auto it:color[col]){
		int a,b;
		a=it.FIR;
		b=it.SEC;
		each[a].clear();
		each[b].clear();
		ok[a]=ok[b]=0;
		q.push(a);
		q.push(b);
	}
	for(auto it:color[col]){
		int a,b;
		a=it.FIR;
		b=it.SEC;
		each[a].PB(b);
		each[b].PB(a);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(!ok[now]){
			++tot;
			dfs(now);
		}
	}
} 
map<mp,int> M;
int main(){
	cin>>n>>m;
	rb(i,1,m)
	{
		int ai,bi,ci;
		scanf("%d %d %d",&ai,&bi,&ci);
		color[ci].PB(II(ai,bi));
	}
	rb(i,1,m){
		if(!color[i].empty()){
			process(i);
		}
	}
	rb(i,1,n) sort(ALL(belong_set[i]));
	int q;
	cin>>q;
	while(q--){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		if(M[II(ui,vi)]){
			printf("%d\n",M[II(ui,vi)]-1);
			continue;
		}
		vector<int> small,large;
		small=belong_set[vi];
		large=belong_set[ui];
		if(belong_set[ui].size()<belong_set[vi].size()){
			swap(small,large);
		}
		int res=0;
		for(auto it:small)
		{
			if(lower_bound(ALL(large),it)!=large.end())
			if(*lower_bound(ALL(large),it)==it){
				res++;
			}
		}
		M[II(ui,vi)]=res+1;
		M[II(vi,ui)]=res+1;
		printf("%d\n",res);
	}
	return 0;
}