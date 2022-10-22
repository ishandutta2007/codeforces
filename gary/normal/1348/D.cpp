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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		LL n;
		cin>>n;
		n--;
		LL is=1;
		vector<int> res;
		while(n-(is<<1)>=(is<<1)||n-(is<<1)==0){
			res.PB(is);
			n-=is*2;
			is<<=1; 
		}
		//is
		if(n){
			if(n<=2*is)
			{
				res.PB(n-is); 
			}
			else{
				int one,two;
				one=n/2;
				two=n-one;
				res.PB(one-is);
				res.PB(two-one);
			}
		}
		cout<<res.size()<<endl;
		for(auto it:res){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	return 0;
}