/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
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
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int edge[500000+20][2];
vector<int> v;
int belong[1500000],is[1500000],degree[1500000+2],vis[1000000+2],num[1000000+2];
vector<int> Can[1000000+1];
bool vvis[1000000+20];
vector<int> eech[1000000+20];
vector<pair<int,int> > g[1000000+20];
vector<int> ans; 
void dfs(int now,int pre=-1){
	while(g[now].size()){
		mp e=g[now].back();
		g[now].pop_back();
		if(vis[(e.SEC+1)/2]){
			continue;
		}
		vis[(e.SEC+1)/2]=1;
		dfs(e.FIR,e.SEC);
	}
	if(pre!=-1){
		ans.PB(pre);
		int pp=pre;
		if(pp&1){
			pp++;
		}
		else{
			pp--;
		}
		ans.PB(pp);
	}
}
void recover(int x){
	memset(vis,0,sizeof(vis));
	memset(is,0,sizeof(is));
	memset(belong,0,sizeof(belong));
	memset(degree,0,sizeof(degree));
	int cnt=0;
	int Index=0;
	for(auto it:v){
		Index++;
		int tail=(it&((1<<x)-1));
		if(!is[tail]){
			is[tail]=++cnt;
		}
		Can[is[tail]].PB(Index);
		belong[it]=is[tail];
		
//		cout<<Index<<"_"<<is[tail]<<endl;
	}
	rb(i,1,n){
		g[belong[edge[i][0]]].PB(II(belong[edge[i][1]],2*i));
		g[belong[edge[i][1]]].PB(II(belong[edge[i][0]],2*i-1));
		
	}
	
	
	dfs(1);
	for(auto it:ans){
		cout<<it<<" ";
	}
}
void DDfs(int now){
//	cout<<now<<endl;
	vvis[now]=1;
	for(auto it:eech[now]){
		if(!vvis[it]){
			DDfs(it);
		}
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>edge[i][0]>>edge[i][1],v.PB(edge[i][0]),v.PB(edge[i][1]),num[i*2-1]=edge[i][0],num[i*2]=edge[i][1];
		bool ok=1;
	rb(id,1,20){
		memset(is,0,sizeof(is));
		memset(belong,0,sizeof(belong));
		memset(degree,0,sizeof(degree));
		int cnt=0;
		for(auto it:v){
			int tail=(it&((1<<id)-1));
			if(!is[tail]){
				is[tail]=++cnt;
			}
			belong[it]=is[tail];
		}
		rb(i,1,n){
			degree[belong[edge[i][0]]]++;
			eech[belong[edge[i][0]]].PB(belong[edge[i][1]]);
			eech[belong[edge[i][1]]].PB(belong[edge[i][0]]);
//			cout<<belong[edge[i][0]]<<"-"<<belong[edge[i][1]]<<endl;
			degree[belong[edge[i][1]]]++;
		}
		rb(i,1,n)
			{
				if(degree[i]&1){
					cout<<id-1<<endl;
					ok=0;
					recover(id-1);
					break;
				}
			 }
		if(!ok) break;
		memset(vvis,0,sizeof(vvis));
		DDfs(1);
		rb(i,1,cnt){
			if(!vvis[i]){
//				cout<<cnt<<endl;
				cout<<id-1<<endl;
				ok=0;
				recover(id-1);
				break;
			} 
		}
		rb(i,1,cnt)
			eech[i].clear();	
		if(!ok) break; 
	}
	if(ok){
	cout<<20<<endl;
	recover(20);	
	}
	
	return 0;
}