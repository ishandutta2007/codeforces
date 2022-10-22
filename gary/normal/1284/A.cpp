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
string s[200],t[200];
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	rb(i,1,n)
		cin>>s[i];
	rb(i,1,m)
		cin>>t[i];
	int q;
	cin>>q;
	while(q--){
		int y;
		cin>>y;
		int a,b;
		a=y%n;
		b=y%m;
		if(a==0) a=n;
		if(b==0) b=m;
		cout<<s[a]<<t[b]<<endl;
	}
	return 0;
}