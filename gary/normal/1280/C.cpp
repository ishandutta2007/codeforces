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
int n,si[200000+10];
LL a,b;
vector<mp> each[200000+10];
void dfs(int now,int prev){
	si[now]=1;
	for(auto it:each[now]){
		if(it.FIR!=prev){
			dfs(it.FIR,now);
			si[now]+=si[it.FIR];
			if(si[it.FIR]&1) a+=it.SEC;
			b+=(LL)(it.SEC)*min(si[it.FIR],n-si[it.FIR]);
		}
	} 
}
void solve(){
	a=b=0; 
	cin>>n;
	n<<=1;
	rb(i,1,n) each[i].clear(),si[i]=0;
	rb(i,1,n-1){
		int u,v,t;
		scanf("%d %d %d",&u,&v,&t);
		each[u].PB(II(v,t));
		each[v].PB(II(u,t));
	}
	dfs(1,-1);
	cout<<a<<" "<<b<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}