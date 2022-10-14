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
LL n,k;
void Know(LL l,LL r){
	SRAND;
	if(l==r){
		cout<<l<<" "<<r<<endl;
		ff;
		exit(0);
	}
//	cerr<<l<<"_--"<<r<<endl;
	if(r-l+1<=6*k)
	{
		LL len=r-l+1;
		LL tmp=random(len);
		cout<<l+tmp<<" "<<l+tmp<<endl;
		ff;
		string type;
		cin>>type;
		if(type=="Yes") exit(0);
		else Know(max(1ll,l-k),min(n,r+k));
	}
	LL mid=(l+r)>>1;
//	cerr<<"Type1"<<endl;
	cout<<l<<" "<<mid<<endl;
	ff;
	string type;
	cin>>type;
	if(type=="Yes"){
		r=mid;
	}
	else{
		l=mid+1;
	}
	r+=k;
	l-=k;
	r=min(n,r);
	l=max(1ll,l);
	Know(l,r);
}
int main(){
	fastio;
	cin>>n>>k;
	Know(1,n);
	return 0;
}