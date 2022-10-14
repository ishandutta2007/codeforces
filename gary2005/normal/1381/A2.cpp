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
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> work(string s){
	vector<int> res;
	rep(i,s.length()){
		if(i!=s.length()-1&&s[i]!=s[i+1]){
			res.PB(i+1);
		} 
	}
	if(s[s.length()-1]=='0'){
		
	}
	else{
		res.PB(s.length());
	}
	return res;
}
void solve(){
	int  n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	vector<int> res,res2;
	res=work(s1);
	res2=work(s2);
	reverse(ALL(res2));
	cout<<res.size()+res2.size()<<" ";
	for(auto it:res) cout<<it<<" ";for(auto it:res2) cout<<it<<" ";cout<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	
	return 0;
}