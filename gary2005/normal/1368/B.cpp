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
	LL k;
	cin>>k;
	string s="codeforces";
	rb(i,1,1000000){
		vector<int> res;
		rb(j,1,10)
			res.PB(i/10);
		int tmp=i-(i/10)*10;
//		cout<<i<<" "<<tmp<<endl;
		rep(j,tmp)
			res[j]++;
		LL kk=1;
		rep(j,10){
			kk*=res[j];
		}
		if(kk>=k){
			rep(j,10){
				rep(l,res[j]){
					cout<<s[j];
				}
			}
			break;
		}
	} 
	return 0;
}