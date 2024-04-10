//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void solve(){
	int n,r;
	scanf("%d %d",&n,&r);
	vector<LL> V;
	rep(i,n){
		LL ai;
		scanf("%I64d",&ai);
		V.PB(ai);
	} 
	sort(ALL(V));
	LL tui=0;
	int res=0;
	rl(i,n-1,0){
		if(i!=n-1) if(V[i]==V[i+1]) continue;
		LL Is=V[i];
		Is-=tui;
		if(Is<=0) break;
		res++;
		tui+=r; 
	}
	cout<<res<<endl;
} 
int main(){
	int q;
	cin>>q;
	while(q--) solve();
	return 0;
}