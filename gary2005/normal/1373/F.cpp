/*
AuThOr Gwj
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
int tmp[1000000+2],n,a[1000000+2],b[1000000+2];
LL check2(int x)
{
	rb(i,1,n){
		tmp[i]=a[i];
	}
	tmp[1]-=x;
	LL res=0;
	rb(i,2,n){
		int rest=b[i-1];
		if(i!=2)rest-=tmp[i-1];
		else rest-=x;
		if(rest<0){
			res+=-rest;
//			cerr<<res<<endl;
			rest=0;
		}
		tmp[i]-=min(tmp[i],rest);
	}
//	cerr<<res<<endl;
	res+=max(0,tmp[1]+tmp[n]-b[n]);
//	cerr<<"#"<<res<<" "<<x<<endl;
	return res;
}
bool check(int x){
	return check2(x-1)>=check2(x);
}
void mian(){
	bool ok=1;
	cin>>n;
	rb(i,1,n)
		cin>>a[i];
	rb(i,1,n)
		cin>>b[i];
//	check2(1);
//	return ;
	if(check2(0)){
		int l=1,r=min(b[1],a[1])+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
//		cerr<<"#"<<l<<check(1)<<endl;
		if(check2(l)){
			ok=0;
		}
	}
	cout<<(ok? "YES":"NO")<<endl;	
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
}
/*
10
2 3 2 1 1 6 3 9 2 1
1 2 1 3 8 5 8 7 2 3
*/