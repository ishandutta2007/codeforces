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
map<pair<char,char>,int> vis; 
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		vis.clear();
		string A,B;
		int n;
		cin>>n;
		cin>>A>>B;
		int res=0;
		rep(i,A.length()){
			if(B[i]<A[i]){
				res=-INF;
				break;
			}
			if(B[i]!=A[i]){
				vis[II(A[i],B[i])]=1;
			}
		}
		int las=-1,mo=-1;
		for(map<pair<char,char>,int> :: IT ite=vis.begin();ite!=vis.end();ite++){
			if(ite->FIR.FIR!=las){
				res++;
				las=ite->FIR.FIR;
				mo=ite->FIR.SEC;
			}
			else{
				vis[II(mo,ite->FIR.SEC)]=1;
			}
		}
		cout<<max(res,-1)<<endl; 
	}
	return 0;
}