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
const LL INF=5e12;
typedef pair<LL,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	fastio;
	string s;
	cin>>s;
	int n=s.length();
	if(n&1){
		cout<<-1<<endl;
		return 0;
	}
	LL ans=0;
	priority_queue<mp,vector<mp>,greater<mp> > q; 
	rep(i,n){
		LL a,b;
		if(s[i]=='('){
			a=0,b=INF;
		}
		if(s[i]==')'){
			a=INF,b=0;
		}
		if(s[i]=='?'){
			cin>>a>>b;
		} 
		s[i]=')';
		ans+=b;
		q.push(II(a-b,i));
		if(~i&1){
			s[q.top().SEC]='(';
			ans+=q.top().FIR;
			q.pop();
		}
	}
	if(ans>=INF){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl<<s<<endl;
	}
	return 0;
}