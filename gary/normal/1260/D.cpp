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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int m,n,k,t,a[200000+10],l[200000+10],r[200000+10],d[200000+10];
bool check(int x){
	if(!x) return 1;
	vector<mp> v; 
	int mini=a[m-x+1];
	rb(i,1,k)
		if(d[i]>mini)
			v.PB({l[i],r[i]});
	sort(ALL(v));
	int ed=-1,sum=0;
	for(auto it:v){
		if(ed<it.FIR-1) {
			ed=it.FIR-1;
		}
		sum+=max(0,it.SEC-ed);
		ed=max(it.SEC,ed);
	}
	return sum+sum+n+1<=t;
}
int main(){
	cin>>m>>n>>k>>t;
	rb(i,1,m) scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	rb(i,1,k) scanf("%d %d %d",&l[i],&r[i],&d[i]);
	int lbound=0,rbound=m+1;
	while(lbound<rbound-1){
		int mid=(lbound+rbound)>>1;
		if(check(mid)){
			lbound=mid;
		} 
		else{
			rbound=mid;
		}
	}
	cout<<lbound<<endl;
	return 0;
}