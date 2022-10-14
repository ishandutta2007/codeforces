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
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL n,m;
LL L[101],H[101];
pair<int,mp> c[101];
void solve(){
	cin>>n>>m;
	rb(i,1,n){
		cin>>c[i].FIR>>c[i].SEC.FIR>>c[i].SEC.SEC; 
	}
	sort(c+1,c+1+n);
//	int las=0;
	c[0].FIR=0;
	L[0]=H[0]=m;
	rb(i,1,n){
		L[i]=L[i-1]-(c[i].FIR-c[i-1].FIR);
		H[i]=H[i-1]+(c[i].FIR-c[i-1].FIR);
		L[i]=max(L[i],c[i].SEC.FIR);
		H[i]=min(H[i],c[i].SEC.SEC);
		if(L[i]>c[i].SEC.SEC||H[i]<c[i].SEC.FIR){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	fastio;
	int q;
	cin>>q;
	while(q--) solve();
	return 0;
}