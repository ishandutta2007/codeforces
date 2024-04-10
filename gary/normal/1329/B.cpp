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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int t;
LL d,m;
void solve(){
	cin>>d>>m;
	LL num[33]={0};
	LL low,up;
	low=1,up=1;
	num[1]=1;
	rb(i,2,30){
		low<<=1;
		up++;
		up<<=1;
		up--;
		if(d<=up){
			up=d;
			num[i]=max(0ll,up-low+1);
			break;
		}
			num[i]=max(0ll,up-low+1);
	}
	LL f[33];
	f[1]=num[1];
	rb(i,2,30){
		f[i]=num[i];
		f[i]%=m;
		rb(j,1,i-1){
			f[i]+=f[j]*num[i]%m;
			f[i]%=m;
		}
	}
	rb(i,1,29)
		f[i+1]+=f[i],f[i+1]%=m;
	cout<<f[30]<<endl;
}
int main(){
	fastio;
	cin>>t;
	while(t--) solve();
	return 0;
}