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
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		vector<int> a(n);
		rb(i,0,n-1) scanf("%d",&a[i]);
		vector<int> len;
		int is=1;
		while(is<n){
			int st=is;
			while(is!=n-1&&a[is]<a[is+1]){
				is++;
			}
			len.PB(is-st+1);
			is++;
		}
		int depth=0,have=1;
		for(int i=0;i<len.size();){
			depth++;
			for(int j=have;j>=1;--j){
				have--;
				have+=len[i];
				i++;
				if(i==len.size()) break;
			}
		}
		printf("%d\n",depth);
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/