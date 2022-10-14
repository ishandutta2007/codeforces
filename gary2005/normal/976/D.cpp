/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
vector<mp> edges;
void dfs(int delta,vector<int> d){
//	cout<<delta<<endl;
//	for(auto it:d){
//		cout<<it<<" ";
//	}
//	cout<<endl;
	if(d.size()==2){
		rb(i,1,d[0]){
			rb(j,i+1,d[1]+1){
				edges.PB(II(delta+i,delta+j));
			}
		}
		return;
	}
	if(d.size()==1){
		int N=d.back()+1;
		rb(i,1,N)
			rb(j,i+1,N)
				edges.PB(II(delta+i,delta+j));
		return;
	}
	int N=d.back()+1,need=d[0];
	vector<int> nd;
	rb(i,1,need){
		rb(j,i+1,N)
			edges.PB(II(delta+i,delta+j));
	}
	delta+=N-d[d.size()-2]-1+need;
	rb(i,1,d.size()-2)
		nd.PB(d[i]-need);
	dfs(delta,nd);
}
//int NNN;
//int z[1002];
int main(){
	fastio;
	R(n);
	vector<int> d;
	rb(i,1,n){
		int di;
		R(di);
		d.PB(di); 
	}
	dfs(0,d);
	cout<<edges.size()<<endl;
	for(auto it:edges){
		cout<<it.FIR<<' '<<it.SEC<<endl;
	}	
	
//	NNN=d.back()+1;
//	for(auto it:edges){
//		z[it.FIR]++;
//		z[it.SEC]++;
//	}
//	vector<int> dd;
//	rb(i,1,NNN)
//		dd.PB(z[i]);
//	sort(ALL(dd));
//	dd.erase(unique(ALL(dd)),dd.end());
//	if(dd==d){
//		cout<<"Yes"<<endl;
//	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/