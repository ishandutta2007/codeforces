/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[100000+10];
int b[100000+10];
int prea[100000+10],preb[100000+10];
bool check(int x){
	int A,B;
	A=(x+n)/4;
	B=x+n-A;
	LL As,Bs;
	As=100ll*x+prea[n];
	As-=prea[min(n,A)];
	if(A>n) As-=100*(A-n);
	Bs=(B<=n? preb[n]-preb[n-B]:preb[n]);
	return As>=Bs;
}
void solve(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),prea[i]=prea[i-1]+a[i];
	rb(i,1,n) scanf("%d",&b[i]),preb[i]=preb[i-1]+b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	rb(i,1,n) prea[i]=prea[i-1]+a[i];
	rb(i,1,n) preb[i]=preb[i-1]+b[i];
	int l=0,r=1e6;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}