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
vector<int> each[200000+1];
int n,max_dep[200000+1],final[200000+1],dp[200000+1],calced[200000+1];
pair<mp,int> store[200000+1];
mp store2[200000+1];
void dfs(int i,int prev){
	if(calced[i]) return ;
//	cout<<i<<" "<<prev<<endl;
	calced[i]=1;
	max_dep[i]=0;
	for(auto it:each[i]){
		if(it!=prev){
			dfs(it,i);
			max_dep[i]=max(max_dep[i],max_dep[it]+1);
		}
	}
	dp[i]=-INF;
	int m1,m2,m3;
	m1=m2=m3=-INF;
	store2[i]=II(-INF,-INF);
	for(auto it:each[i]){
		if(it!=prev){
			if(dp[it]>store2[i].SEC) store2[i].SEC=dp[it];
			if(store2[i].FIR<store2[i].SEC) swap(store2[i].FIR,store2[i].SEC);
			if(max_dep[it]>m3) m3=max_dep[it];
			if(m2<m3) swap(m2,m3);
			if(m1<m2) swap(m1,m2);
		}
	}
	store[i]=II(II(m1,m2),m3);
	dp[i]=store2[i].FIR+1;
	dp[i]=max(dp[i],m1+m2+2);
}
void change(int now,int prev){
	final[now]=dp[now];
	for(auto it:each[now]){
		if(it!=prev){
			int s1=dp[now],s2=max_dep[now];
			if(store[now].FIR.FIR==max_dep[it]) max_dep[now]=max(0,store[now].FIR.SEC+1);
			else max_dep[now]=max(0,store[now].FIR.FIR+1);
			if(store2[now].FIR==dp[it]){
				dp[now]=store2[now].SEC+1;
			}
			else
			dp[now]=store2[now].FIR+1;
			if(store[now].FIR.FIR==max_dep[it])
			{
				dp[now]=max(dp[now],store[now].FIR.SEC+store[now].SEC+2);
			}
			else{
				if(store[now].FIR.SEC==max_dep[it]){
					dp[now]=max(dp[now],store[now].FIR.FIR+store[now].SEC+2);
				}
				else{
					dp[now]=max(dp[now],store[now].FIR.FIR+store[now].FIR.SEC+2);
				}
			}
			calced[it]=0;
			dfs(it,-1);//change
			change(it,now);
			dp[now]=s1,max_dep[now]=s2;//change back
		}
	}
}
int OK=0;
void SEARCH(int now,int nt,int aim,int prev=-1){
	if(OK) return;
	if(nt==aim){
		OK=1;
		cout<<now<<" ";
		return;
	}
	for(auto it:each[now]){
		if(it!=prev){
			SEARCH(it,nt+1,aim,now);
		}
	}
}
void print(int a,int prev=-1){
	for(auto it:each[a]){
		if(it!=prev)
		if(dp[a]==dp[it]+1){
			print(it,a);
			return;
		}
	}
	int m1,m2;
	m1=m2=-INF;
	for(auto it:each[a]){
		if(it!=prev){
			if(max_dep[it]>m2) m2=max_dep[it];
			if(m1<m2) swap(m1,m2);
		}
	}
	if(dp[a]!=m1+m2+2)
	{
		cout<<"!erro\n";
		exit(0);
	}
	for(auto it:each[a]){
		if(it!=prev){
			if(max_dep[it]==m1){
				OK=0;
				SEARCH(it,0,m1,a);
				m1=-1;
			}
			else{
				if(max_dep[it]==m2){
					OK=0;
					SEARCH(it,0,m2,a);
					m2=-1;
				}
			} 
		}
	}
	return; 
}
int main(){
	fastio;
//	freopen("test.in","r",stdin);
	cin>>n;
	rb(i,2,n)
		{
			int u,v;
			cin>>u>>v;
			each[u].PB(v),each[v].PB(u);
		}
	dfs(1,-1);
	change(1,-1);
	int res=0;
	rb(i,1,n)
		res=max(res,final[i]);
	rb(i,1,n)
		if(final[i]==res){
			memset(calced,0,sizeof(calced));
			dfs(i,-1);
			cout<<dp[i]<<endl;
			cout<<i<<" ";
			print(i);
			break;
		}
	return 0;
}