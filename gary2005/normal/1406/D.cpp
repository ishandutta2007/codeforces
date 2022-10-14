/*
{By GWj
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
LL diff[100000+20],a[100000+20],sum;
LL calc(){
	LL l,r;
	l=0,r=a[1]+sum;
	if(r<l) swap(l,r);
	return l+(r-l+1)/2;
}
int main(){
	fastio;
	R(n);
	rb(i,1,n)
		R(a[i]);
	rb(i,2,n)
		diff[i]=a[i]-a[i-1],sum+=max(0ll,diff[i]);
	cout<<calc()<<endl;
	int q;R(q);
	while(q--){
		int l,r,x;
		cin>>l>>r>>x;
		if(l==1) a[1]+=x;
		if(l!=1){
			if(diff[l]>0) sum-=diff[l];
			diff[l]+=x;
			sum+=max(0ll,diff[l]);
		}
		if(r!=n){
			if(diff[r+1]>0) sum-=diff[r+1];
			diff[r+1]-=x;
			sum+=max(0ll,diff[r+1]);
		}
		cout<<calc()<<endl;
	}
	return 0;
}