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
int n;
int a[100000+20],b[100000+20];
struct Line{
	LL k,b;
	Line(){}
	Line (LL A,LL B){
		k=A,b=B;
	}
};

deque<Line> l;

LL dp[100000+20];
bool check(Line A,Line B,Line C){ 
	return 1.0*(A.b-B.b)*(C.k-A.k)>=1.0*(A.b-C.b)*(B.k-A.k);
}
void insert(Line C){	
	while(l.size()>1){
		Line B,A;
		B=l.back();
		l.pop_back();
		A=l.back();
		if(!check(A,B,C)){
			l.PB(B);
			break;
		}
	}
	l.PB(C);
}
LL get(Line L,LL A){
	return A*L.k+L.b;
}
LL query(LL x){
	while(l.size()>1){
		if(get(l[0],x)>=get(l[1],x)) l.pop_front();
		else break;
	}	
	return get(l[0],x);
}
int main(){
	scanf("%d",&n);
	rb(i,1,n)
		scanf("%d",&a[i]);
	rb(i,1,n)
		scanf("%d",&b[i]);
	dp[1]=0;
	insert(Line(b[1],0));
	rb(i,2,n){
		dp[i]=query(a[i]);
		insert(Line(b[i],dp[i]));
	}	
	cout<<dp[n]<<endl;	
	return 0;
}
/** 
  *
  *
  *
  *
  **/