/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int k,n,m;
string s,t;
int sum[500000][4];
bitset<200000> bs[4],res;
int main(){
	fastio;
	R(n);
	R(m);
	R(k);
	R2(s,t);
	rep(i,n)
	{
		if(s[i]=='A'){
			s[i]=0;
		}
		if(s[i]=='G'){
			s[i]=1;
		}
		if(s[i]=='C'){
			s[i]=2;
		}
		if(s[i]=='T'){
			s[i]=3;
		}
	}	
	rep(i,m)
	{
		if(t[i]=='A'){
			t[i]=0;
		}
		if(t[i]=='G'){
			t[i]=1;
		}
		if(t[i]=='C'){
			t[i]=2;
		}
		if(t[i]=='T'){
			t[i]=3;
		}
	}	
	k++;
	rep(i,n){
		
		sum[max(0,i-k+1)][s[i]]++;
		sum[i+k][s[i]]--;
	}
	rep(i,4)
		rep(j,n)
			if(j)
			sum[j][i]+=sum[j-1][i];
//	rep(i,4){
//		rep(j,n){
//			cout<<sum[j][i]<<" ";
//		}
//		cout<<endl;
//	}
	rep(i,n)
		rep(j,4)
			if(sum[i][j]){
				bs[j].set(i);
			}
	rep(i,n-m+1) res.set(i);
	rep(i,m){
		res&=(bs[t[i]]>>i);
	}
	cout<<res.count()<<endl;
	return 0;
}