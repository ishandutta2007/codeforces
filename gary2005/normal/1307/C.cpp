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
LL dp1[26],dp2[26][26];
string s;
int n;
int main(){// 
	fastio;
	cin>>s;
	n=s.length();
	LL res=0;
	rep(i,n){
		rep(j,26)
			dp2[j][s[i]-'a']+=dp1[j],res=max(res,dp2[j][s[i]-'a']);
		dp1[s[i]-'a']++;
		res=max(res,dp1[s[i]-'a']);
	}
	cout<<res<<endl;
	return 0;
}