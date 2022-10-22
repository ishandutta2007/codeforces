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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n;
int a[100000+20];
signed main(){
	fastio;
	int t;
	cin>>t;
	while(t--){cin>>n;
		int k,z;
		cin>>k>>z;
	rb(i,1,n) cin>>a[i];
	LL res=a[1],sum=a[1],maxi=0;
	rb(i,2,n){
		sum+=a[i];
		maxi=max((LL)a[i]+a[i-1],maxi);
		LL ok=k-i+1;
		if(ok<0) break;
		if(ok>0) 
		ok=min((ok)/2,(LL)z);
		else ok=0;
		res=max(res,sum);
		res=max(res,sum+ok*maxi);
		LL tmp=sum,tmp2=0;
		int rest=k-i+1; 
		rb(j,1,1000)
		{
			if(rest==0) break;
			rest--;
			if(j%2==1){
				if(tmp2==z) break;
				tmp2++;
				tmp+=a[i-1];
			}
			else{
				tmp+=a[i];
			}
			if(tmp2==z) break;
			if(rest==0) break;
		}
//		cout<<i<<" "<<tmp<<endl;
		res=max(res,tmp);
	}
	cout<<res<<endl;
	}
	return 0;
}