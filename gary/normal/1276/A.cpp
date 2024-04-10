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
void solve(){
	string s;
	cin>>s;
	int len=s.length();
	set<int> res;
	if(len>=3)
	rep(i,len-3+1){
		if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
			if(i-1>=0&&s[i-1]!='o')
			res.insert(i);
			else
			res.insert(i+1);
		}
		if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
			if(i+3<len&&s[i+3]!='o')
			res.insert(i+2);
			else
			res.insert(i+1);
		}
	}
	cout<<res.size()<<"\n";
	for(auto it:res){
//		s[it]='&'; 
		cout<<it+1<<" ";
	}
//	cout<<s<<endl;
	cout<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	
	return 0;
}