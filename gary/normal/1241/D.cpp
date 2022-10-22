//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[300000+10],saven;
int s[300000+10],e[300000+10],dp[300000+10];
//priority_queue<mp> q;
bool cmp(mp A,mp B) {
	return A.SEC<B.SEC;
}
void solve(){
	map<int,int> Lisan;
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]),Lisan[a[i]]=1,s[i]=e[i]=-1;
	int tot=0;
	for(map<int,int> :: IT ite=Lisan.begin();ite!=Lisan.end();ite++){
		ite->SEC=++tot; 
	}saven=n;
	rb(i,1,n) a[i]=Lisan[a[i]];
	rb(i,1,n){
		if(s[a[i]]==-1){
			s[a[i]]=i;	
		}
		e[a[i]]=i;
//		cout<<a[i]<<" "<<s[a[i]]<<" "<<e[a[i]]<<endl;
	}
//	rb(i,1,n) cout<<a[i]<<" ";cout<<endl;
	n=tot;
//	memset(dp,0,sizeof(dp));
//	q.clear();
	dp[1]=1;
	rb(i,2,n){
		if(s[i]>e[i-1])
		dp[i]=dp[i-1]+1;
		else 
		dp[i]=1;
//		cout<<dp[i]<<endl;
	}
	int is=-INF;
	rb(i,1,n) is=max(is,dp[i]);
	cout<<n-is<<endl;
}
int main(){
	int q;
	cin>>q;
	int tot=0;
	while(q--)
	{
		tot++;
		solve();
	}
	return 0;
}