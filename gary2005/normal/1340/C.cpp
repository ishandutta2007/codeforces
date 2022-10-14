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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,d[10000+2],dp[10000+1][1000],g,r;
typedef mp pp; 
deque<pp> dq;
bool used[10000+1][10000];
int main(){
	fastio;
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>m;rb(i,1,m) cin>>d[i];cin>>g>>r;
	sort(d+1,d+1+m);
	dp[1][0]=0;
	dq.push_front(II(1,0));
	while(!dq.empty()){
		int x,y,val;
		pp xx=dq.front();
		dq.pop_front();
		x=xx.FIR;
		y=xx.SEC;
		if(used[x][y]) continue;
		used[x][y]=1;
		val=dp[x][y];
		//if(val!=dp[x][y]) continue;
		int tmpval;
		int atmost=g-y;
		if(x-1){
			tmpval=val;
			if(d[x]-d[x-1]<atmost){
				if(dp[x-1][y+(d[x]-d[x-1])]>val){
					dp[x-1][y+(d[x]-d[x-1])]=val;
					dq.push_front(II(x-1,y+(d[x]-d[x-1])));
				}
			}
			if(d[x]-d[x-1]==atmost){
				if(dp[x-1][0]>val+1){
					dp[x-1][0]=val+1;
					dq.push_back(II(x-1,0));
				}
			}
		}
		if(x+1<=m){
			tmpval=val;
			if(d[x+1]-d[x]<atmost){
				if(dp[x+1][y+d[x+1]-d[x]]>val){
					dp[x+1][y+d[x+1]-d[x]]=val;
					dq.push_front(II(x+1,y+(d[x+1]-d[x])));
				}
			}
			if(d[x+1]-d[x]==atmost){
				if(dp[x+1][0]>val+1){
					dp[x+1][0]=val+1;
					dq.push_back(II(x+1,0));
				}
			}
		}	
	} 
	LL res=INF;
	rep(i,g){
		if(!i){
			res=min(res,(LL)dp[m][i]*g+(LL)(dp[m][i]-1)*r);
		}
		else{
			res=min(res,(LL)(dp[m][i])*(g+r)+i);
		}
	} 
	if(res==INF){
		cout<<-1<<endl;
	}
	else{cout<<res<<endl;
	}
	return 0;
}