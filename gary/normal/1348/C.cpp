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
//	string s[100000+20];
	while(t--){
		int n,k;
		cin>>n>>k;
		string ss;
		cin>>ss;
//		rb(i,1,k)
//			s[i]="";
		sort(ALL(ss));
		string res="";
		res+=ss[k-1];
		if(k==n){
			cout<<res<<endl;;
			continue;
		}
		if(ss[k-1]!=ss[0]){
			cout<<res<<endl;
			continue;
		}
		if(ss[k]!=ss[n-1]){
			rb(i,k,n-1){
				res+=ss[i];
			}
			cout<<res<<endl;
		}
		else{
			int id=k;
			rb(i,k,n-1){
				if(id==k){
					res+=ss[i];
				}
				id--;
				if(id==0) id=k;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}