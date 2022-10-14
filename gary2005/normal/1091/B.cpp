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
int x[1001],y[1001];
int x2[1001],y2[1001];
map<mp,int>M;
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,1,n) cin>>x[i]>>y[i];
	rb(i,1,n){
		int a,b;
		cin>>a>>b;
		x2[i]=a;
		y2[i]=b;
		M[II(a,b)]=1;
	}
	mp T;
	rb(i,1,n){
		T=II(x[1]+x2[i],y[1]+y2[i]);
		int OK=1;
		rb(j,2,n){
			int Tx,Ty;
			Tx=T.FIR-x[j];
			Ty=T.SEC-y[j];
			OK=OK&M[II(Tx,Ty)];
		}
		if(OK) break;
	}cout<<T.FIR<<" "<<T.SEC<<endl;
	return 0;
}