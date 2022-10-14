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
int n,m;
struct Move{
	vector<int>  moveto;//
	Move operator * (Move B){
		Move ret;
		ret.moveto=vector<int>(moveto.size());
		rep(i,moveto.size())
			ret.moveto[i]=B.moveto[moveto[i]];
		return ret;
	} 	
};
Move Emt;
Move quick(Move A,int times){
	Move ret;
	if(times==0){
		return Emt;	
	}
	ret=quick(A,times>>1);
	ret=ret*ret;
	if(times&1)
		ret=ret*A;
	return ret;
}

int main(){
	string s;
	string rest;
	cin>>s;
	n=s.length();
	scanf("%d",&m);
	rep(i,n)
		Emt.moveto.PB(i);
	rb(Q,1,m){
		int k,d;
		scanf("%d%d",&k,&d);
		rest=s;
		Move To;
		To.moveto=vector<int> (n);
		vector<int> test(n);
		rep(i,n)
			test[i]=i;
		int is=0;
		rep(i,d){
			for(int j=i;j<k;j+=d){
				test[is++]=j;
			}
		}
		for(int j=k;j<n;++j){
			test[j]=j;
		}
		test.PB(test[0]);
		rep(i,test.size()){
			if(i){
				To.moveto[test[i]]=i-1;
			}
		}
		To=quick(To,n-k+1);
		string fake;
		fake.clear(); 
		rep(i,n){
			rest[To.moveto[i]]=s[i];
		}		
		int id=k-1;
		rep(i,n){
			fake+=rest[id];
			id++;
			id%=n;
		}
		rest=fake;
		printf("%s\n",fake.c_str());
//		cout<<fake<<endl;
		s=rest;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/