/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int t;
	cin>>t;
	while(t--){
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		int k;
		cin>>k;
		int x,y;
		x=int(ceil(a/c)),y=int(ceil(b/d));
		if(x+y<=k){
			cout<<x<<" "<<y<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}