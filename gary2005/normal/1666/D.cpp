#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s,t;
		cin>>s>>t;
		map<char,vector<int> > ocs,oct;
		rep(i,s.length()) ocs[s[i]].PB(i);
		rep(i,t.length()) oct[t[i]].PB(i);
		bool ok=1;
		vector<int> tmp;
		for(auto it:oct){
			if(ocs[it.FIR].size()<it.SEC.size()){
				ok=0;
				break;
			}
			reverse(ALL(ocs[it.FIR]));
			rep(i,it.SEC.size()) tmp.PB(ocs[it.FIR][i]);
		}
		sort(ALL(tmp));
		string rest;
		for(auto it:tmp) rest.PB(s[it]);
		if(rest==t&&ok){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
    return 0;
}