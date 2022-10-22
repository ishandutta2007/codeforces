/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,k;
LL check(LL A){
	if(A>n) return 0;
	if(A+1>n) return 1;
	if(A*2>n) return 2;
	LL now=2,mi=2,add=4;
	while(n){//cout<<now<<" "<<add<<endl;
		if((mi<<1ll)*A<=n){
			now+=add;
			add<<=1ll;
			mi<<=1ll;
		}
		else{
			now+=min(n-A*mi+1,add);
			break;
		}
		
	}
	return now;
}
LL check2(LL B){
	if(B>n) return 0; 
	return 1+check(B<<1ll);
}
int main(){
	cin>>n>>k;
	LL l,r;
	l=1,r=n/2+1;//	 
//	cout<<l<<" "<<r<<endl;
	while(l<r-1){
		LL mid=(l+r)>>1;
		if(check(mid*2)>=k){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	if(check(2)<k){
		l=-1;
	}
	LL l2,r2;
	l2=0,r2=n/2+1;// 
	if(n&1) ;
	else r2--;
	while(l2<r2-1){
		LL mid=(l2+r2)>>1;
		if(check2(mid*2+1)>=k){
			l2=mid;
		}
		else{
			r2=mid;
		}
	}
//	cout<<check(499950)<<endl;
	cout<<max(l*2,l2*2+1)<<endl;
	return 0;
}