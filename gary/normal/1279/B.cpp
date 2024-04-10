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
int n;LL s;int a[100000+10];
LL sum[100000+10];
int res1=0,res2=0;
void solve(){
	res1=res2=0;
	cin>>n>>s;
	rb(i,1,n) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	rb(i,1,n){
		if(sum[i]<=s){
			res2=i;
		}
		else{
			break;
		}
	}
	rb(i,1,n){
		if(sum[i-1]<=s){
		int l=i,r=n+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(sum[mid]-a[i]<=s) l=mid;
			else r=mid; 
		}
		if(l-1>res2){
			res2=l-1;
			res1=i;
		}	
		}
	}
	cout<<res1<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}