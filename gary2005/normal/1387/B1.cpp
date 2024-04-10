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
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
vector<int> g[100000+20];
LL dp[100000+20][2],od[100000+2][2],save[100000+2],sp[100000+2];
void dfs(int now,int pre=0){
	if(pre&&g[now].size()==1){
		dp[now][0]=10000000000+2;
		dp[now][1]=0;
		return ;
	}
	int ok=0;
	dp[now][0]=10000000000+2;
	sp[now]=0;
	LL st=0;
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now);
			sp[now]+=dp[it][0];
			if(!ok){
				ok=it;
				dp[now][1]=dp[it][1]+2;
//				if(now==3) cout<<it<<" "<<dp[now][1]<<" "<<dp[it][1]<<endl;
			}
			else{
				int s1,s2;
				s1=dp[now][0];
				s2=dp[now][1];
				dp[now][1]=min(st+dp[it][1]+2,min(s1+dp[it][1]+2,s2+dp[it][0]));
				dp[now][0]=min(s2+dp[it][1]+2,s1+dp[it][0]);
			}
			st+=dp[it][0];
		}
	}
	od[now][0]=dp[now][0];
	od[now][1]=dp[now][1];
	save[now]=dp[now][0];
	dp[now][0]=min(dp[now][0],dp[now][1]);
	dp[now][1]=min(sp[now],dp[now][1]);
	dp[now][1]=min(dp[now][1],save[now]);
}
int mo[100000+2];
vector<pair<LL,int > > res;
LL tmp=0;
int f(bool pa,LL val,bool sp=0){
	bool alr=0;
	if(tmp==val&&alr==pa&&!sp){
			return -1;
		}
	rep(i,res.size()){
		alr^=1;
		tmp+=res[i].FIR;
		if(tmp==val&&alr==pa){
			return i;
		}
	}
	assert(0);
}
mp recover(int now,int st,int pre=0){
//	cout<<now<<","<<st<<"!"<<pre<<"--"<<dp[now][st]<<endl;
	if(pre&&g[now].size()==1){
		return II(now,now);
	}
	tmp=0;
	vector<pair<LL,int> > cop;
	res.clear();
	for(auto it:g[now]){
		if(it!=pre){
			tmp+=dp[it][0];
			res.PB(II(dp[it][1]+2-dp[it][0],it));
		}
	}
	sort(ALL(res));
	for(auto it:res)
		cop.PB(it);
	int x=-1;
	vector<mp> RR;
	if(st==0){
		if(dp[now][0]==od[now][1]){
			x=f(1,dp[now][st]);
			
			rep(i,x+1)
				RR.PB(recover(cop[i].SEC,1,now));
			rb(i,x+1,cop.size()-1){
				recover(cop[i].SEC,0,now);
			}
		bool alr=1;
		mp las=II(now,now);
		rep(i,x+1){
			alr^=1;
			if(!alr){
				mo[las.FIR]=RR[i].SEC;
				mo[RR[i].FIR]=las.SEC;
				continue;
			}
			las=RR[i];
		}
		}
		else{
		//	if(now==3){
//				cout<<tmp<<"_"<<dp[now][st]<<" "<<res[0].SEC<<endl;
//				for(auto it:res){
//					cout<<it.SEC<<" ";
//				} cout<<endl;
//			}
			x=f(0,dp[now][st],1);
			rep(i,x+1)
				RR.PB(recover(cop[i].SEC,1,now));
			rb(i,x+1,cop.size()-1){
				recover(cop[i].SEC,0,now);
			}
			bool alr=0;
			mp las=II(now,now);
			bool firs=0;
			rep(i,x+1){
				alr^=1;
			if(!alr){
				if(!firs){
					mo[las.FIR]=now;
					mo[now]=RR[i].SEC;
					mo[RR[i].SEC]=las.SEC;
					firs=1;
				}
				else{
					mo[las.FIR]=RR[i].SEC;
					mo[RR[i].FIR]=las.SEC;
				}
				continue;
			}
			las=RR[i];
			}
		}
		
		return II(0,0);
	}
	else{
		if(dp[now][1]==sp[now]){
			for(auto it:g[now]){
				if(it!=pre){
					recover(it,0,now);
				}
			}
			return II(now,now);
		}
		if(dp[now][1]==od[now][1]){
//			if(now==3){
//				for(auto it:res){
//					cout<<it.SEC<<" ";
//				}
//				cout<<endl;
//			}
			x=f(1,dp[now][st]);
			rep(i,x+1)
			RR.PB(recover(cop[i].SEC,1,now));
			rb(i,x+1,cop.size()-1){
			recover(cop[i].SEC,0,now);
			}
			bool alr=0;
			mp las;
			rep(i,x+1){
				alr^=1;
				if(!alr){
					mo[las.FIR]=RR[i].SEC;
					mo[RR[i].FIR]=las.SEC;
					continue;
				}
				las=RR[i];
			}
			mo[now]=las.SEC;
//			if(now==3) cout<<RR.size()<<" "<<las.FIR<<endl;
			return II(las.FIR,now);
		}
		else{
			x=f(0,dp[now][st]);
			rep(i,x+1){
				

				RR.PB(recover(cop[i].SEC,1,now));
			}
				rb(i,x+1,cop.size()-1){
					recover(cop[i].SEC,0,now);
				}			
			bool alr=0;
			mp las;
			rep(i,x+1){
				alr^=1;
				if(!alr){
					mo[las.FIR]=RR[i].SEC;
					mo[RR[i].FIR]=las.SEC;
					continue;
				}
				las=RR[i];
			}
			return II(now,now);
		}
	}
}
int vis[100000+2];
int main(){
	fastio;
	R(n);
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[v].PB(u);
		g[u].PB(v);
	}
	dfs(1);
//	cout<<dp[2][1]<<endl;
	cout<<dp[1][0]<<endl;
	recover(1,0);
	rb(i,1,n){
//		assert(mo[i]>0);
//		assert(mo[i]<=n);
//		assert(!vis[mo[i]]);
		vis[mo[i]]=1;
		cout<<mo[i]<<" ";
	}cout<<endl;
	return 0;
}
/*

9
1 2
1 3
2 4
2 5
3 6
3 7
3 8
3 9

*/