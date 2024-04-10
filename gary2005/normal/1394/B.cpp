/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
bool cant[10][10][10][10];
int n,k;
int id[200000+20],od[200000+20];
vector<mp> g[200000+20];
bool cmp(mp A,mp B){
	return A.SEC<B.SEC;
}
int ID[10][10]; 
vector<int> gg[200],ii[200000+20];
int res=0;
vector<int> num; 
bool take[200];
bool no[200][200];
int si[200];
void dfs(int now){
	if(now==k+1){
		bool ok=1;
		int ccn=0;
		rep(i,k){
			ccn+=si[ID[i+1][num[i]]];
			rep(j,i){
				if(no[ID[i+1][num[i]]][ID[j+1][num[j]]]){
					ok=0;
				}
			}
		}
		if(ccn!=n) ok=0;
//		if(ok){
//			rep(i,k)
//				cout<<num[i]<<" ";
//				cout<<endl; 
//		}
		res+=ok;
		return;	
	}
	rb(i,1,now){
		num.PB(i);
		dfs(now+1);
		num.POB();
	}
}
bitset<100> bs[200000+2];
int main(){
	fastio;
	R(n);
	int m;
	int _CNT=0;
	rb(i,1,9)
		rb(j,1,9)
			ID[i][j]=++_CNT;
	R(m);
	R(k);
	rb(i,1,m){
		int u,v,t;
		R2(u,v);
		R(t);
		g[u].PB(II(v,t));
		id[v]++;
		od[u]++;
	}
	rb(i,1,n){
		if(!id[i]||!od[i]){
			cout<<0<<endl;
			return 0;
		}
	}
	rb(i,1,n){
		sort(ALL(g[i]),cmp);
		rep(j,g[i].size()){
			ii[g[i][j].FIR].PB(ID[g[i].size()][j+1]);
		} 
	}
	rb(i,1,n){
		int las=-1;
		for(auto it:ii[i]){
			gg[it].PB(i);
			bs[i].set(it);
		}
	}
	rb(i,1,81){
		sort(ALL(gg[i]));
		gg[i].erase(unique(ALL(gg[i])),gg[i].end());
	}
	bitset<100> tmp;
	rb(i,1,81){
		tmp.reset();
		for(auto it:gg[i]){
			si[i]++;
			tmp|=bs[it];
		}
		rb(j,1,81){
			if(tmp[j]){
				no[i][j]=1;
			}
		}
	}
	dfs(1);
	cout<<res<<endl;
	return 0;
}