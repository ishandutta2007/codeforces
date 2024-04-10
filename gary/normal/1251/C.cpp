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
int t;
string s;
void solve(){
	cin>>s;
	queue<char> odd,even;
	int len=s.length();
	rep(i,len){
		if((s[i]^48)&1) odd.push(s[i]);
		else even.push(s[i]); 
	}
	rep(i,len){
		if(even.empty()) cout<<odd.front(),odd.pop();
		else
		if(odd.empty()) cout<<even.front(),even.pop();
		else
		if((int)even.front()>(int)odd.front()) cout<<odd.front(),odd.pop();
		else cout<<even.front(),even.pop();
	}
	puts("");
}
int main(){
	cin>>t;
	while(t--) solve();
	return 0;
}