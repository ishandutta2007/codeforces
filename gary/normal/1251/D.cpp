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
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
int t,n;LL s,X;
mp a[200000+10];
bool cmp(mp A,mp B){
	if(A.SEC>=X&&B.SEC>=X) return A.FIR>B.FIR;
	return A.SEC>B.SEC;
}
bool check(LL x){
	X=x; 
	sort(a+1,a+1+n,cmp);
	if(a[n/2+1].SEC<x) return 0;
	LL res=0;
	rb(i,1,n/2+1){
		res+=max(a[i].FIR,x);
	} 
	if(a[n/2+2].FIR>x){
		return 1;
	}
	rb(i,n/2+2,n){
		res+=a[i].FIR;
	}
	return res<=s;
}
void solve(){
	scanf("%d %I64d",&n,&s);
	rb(i,1,n) scanf("%I64d %I64d",&a[i].FIR,&a[i].SEC);
	LL l=1,r=s+1;
	while(l<r-1){
		LL mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
//	cout<<check(1337)<<endl;
	printf("%I64d\n",l);
}
int main(){
	cin>>t;
	while(t--) solve();
	return 0;
}