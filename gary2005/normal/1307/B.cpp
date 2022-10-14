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
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n,x;
		int mm=-1;
		cin>>n>>x;
		int M=-1;
		rb(i,1,n){
			int a;
			cin>>a;
			M=max(a,M);
			if(a>x) a=-1;
			mm=max(mm,a);
		}
		if(mm==-1) cout<<2<<endl;
		else{
			if(M>=(x+1)/2){
				cout<<min((x/mm)+bool(x%mm),2)<<endl;
			}
			else
			cout<<(x/mm)+bool(x%mm)<<endl;
		}
	}
	return 0;
}