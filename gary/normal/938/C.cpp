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
#define int LL 
int  TMP;
bool check(int n,int x){
	if(n<x) swap(n,x);
	if(n==x) return 0;
	if((n-x)&1) return 0;
//	cout<<n<<"**"<<x<<endl;
	int tmp=n;
	n=(n+x)>>1;
	x=tmp-n;
//	cout<<n<<endl;
//	cout<<n<<"_"<<x<<endl;
	int l=1,r=2e9+1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if((n)/mid<x) r=mid;
		else l=mid;
	}//cout<<l<<endl;
	if((n)/l!=x) return 0;
	cout<<n<<" ";cout<<l<<endl;
	return 1;
}
signed main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;TMP=x;
		if(x==0){
			cout<<1 <<" "<<1<<endl;continue;
		}
		int ok=0;
		for(int i=1;i*i<=x;i++){
			if(x%i==0)
			if(check(i,x/i)){
				ok=1;				break;
			}
		}
		if(!ok){
			cout<<-1<<endl;
		}
	} 
	return 0;
}
/*
100100
999954147
999954147


36514 2
*/