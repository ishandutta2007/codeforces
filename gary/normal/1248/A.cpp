/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void solve(){
	int n,m;
	int cnt1,cnt2;
	cnt1=cnt2=0;
	scanf("%d",&n);
	rb(i,1,n) {
		int pi;
		scanf("%d",&pi);
		if(pi&1) cnt1++;
	}
	scanf("%d",&m);
	rb(i,1,m) {
		int pi;
		scanf("%d",&pi);
		if(pi&1) cnt2++;
	}
	printf("%I64d\n",(LL)(cnt1)*(cnt2)+(LL)(n-cnt1)*(m-cnt2));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}