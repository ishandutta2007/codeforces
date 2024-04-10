/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,k;
int bit[200000+10]={0};
int sum(int i){
	if(i>n) i=n;
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=n){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int a[200000+20],b[200000+20],pos[200000+20];
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&k);
		rb(i,1,n) scanf("%d",&a[i]),pos[a[i]]=i;
		rb(i,1,k) scanf("%d",&b[i]),b[i]=pos[b[i]];
		set<int> s;
		rb(i,1,k) s.insert(b[i]);
		rb(i,1,n) bit[i]=0;
		LL rest=1;
		rb(i,1,k){
			s.erase(b[i]);
			auto ite=s.lower_bound(b[i]);
			bool L=0,R=0;
			int r,l;
			if(ite!=s.end()) r=*ite;
			else r=n+1;
			if(ite!=s.begin()){
				ite--;
				l=*ite;
			}
			else l=0;
				R=(r-1-b[i]-(sum(r)-sum(b[i]))>0);
				L=(b[i]-l-1-(sum(b[i])-sum(l))>0);
			rest*=L+R;
			add(b[i]);
			rest%=998244353;	
		}
		cout<<rest<<endl;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/