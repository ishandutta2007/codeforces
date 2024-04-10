/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
pair<int,int> a[200000+20];
int res[200000+20];
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		R(n);
		LL k;
		R(k);
		rb(i,1,n) R(a[i].FIR),a[i].SEC=i;
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		if(k&1){
			rb(i,1,n)
			{
				res[a[i].SEC]=a[1].FIR-a[i].FIR;
			}
		}
		else{
			rb(i,1,n){
				res[a[i].SEC]=a[i].FIR-a[n].FIR;
			}
		}rb(i,1,n) cout<<res[i]<<" ";cout<<endl;
	}
	return 0;
}