/*
AuThOr GaRyMr
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> ind_set;
int n,m,d[100000+20],used[100000+20];
vector<int> each[100000+20];
set<pair<int,int>  > degree;
vector<int> cycle;
int is[100000+20];
	int sq;
void dfs(int now){
	used[now]=1;
	cycle.PB(now);
	for(auto it:each[now]){
		if(!used[it]&&d[it]>=sq-1){
			dfs(it);
			break;
		} 
	} 
} 
int main(){
	fastio;
	cin>>n>>m;
//	cin>>n>>m;
	rb(i,1,1000)
		if(i*i>=n){
			sq=i;
			break;
		}
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u); 
		d[u]++;
		d[v]++;
	}
	rb(i,1,n){
		degree.insert(II(d[i],i));
	}
	set<pair<int,int> > :: IT b;
	rb(i,1,n){
		if(degree.begin()==degree.end()) break;
		b=degree.begin();
		if((*b).FIR>=sq-1) break;
//		cout<<(*b).SEC<<endl;
		ind_set.PB((*b).SEC);
		if(ind_set.size()==sq){
			cout<<1<<endl;
			rep(j,ind_set.size()){
				cout<<ind_set[j]<<" "; 
			}
			cout<<endl;
			return 0;
		}
		for(auto it:each[(*b).SEC]){
			if(degree.find(II(d[it],it))!=degree.end()){
				for(auto it2:each[it]){
					if(it2!=(*b).SEC)
					if(degree.find(II(d[it2],it2))!=degree.end()){
						degree.erase(II(d[it2],it2));
						d[it2]--;
						degree.insert(II(d[it2],it2));
					}
					
				}
				degree.erase(II(d[it],it));
				d[it]=0; 
			}
		}
		d[(*b).SEC]=0;
		degree.erase(b);
	}
//	return 0;
	rb(i,1,n){
		if(d[i]>=sq-1){
			dfs(i);
			break;
		}
	} 
	rep(i,cycle.size()){
		is[cycle[i]]=i;
	}
	int minm=INF;
	for(auto it:each[cycle[cycle.size()-1]]){
		if(d[it]>=sq-1)
		minm=min(minm,is[it]);		
	}
	cout<<2<<endl;
	cout<<cycle.size()-minm<<endl;
	rb(i,minm,cycle.size()-1){
		cout<<cycle[i]<<" ";
	}
	return 0;
}