/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
double dp[1<<18],a[20][20];
bool get_mask(int mask,int pos){
	return mask&(1<<(pos-1));
}
int erase_mask(int mask,int pos){
	return mask-(1<<(pos-1));
}
int main(){
//	fastio;
	cin>>n;
	rb(i,1,n)
		rb(j,1,n)
			cin>>a[i][j];
	dp[(1<<n)-1]=1.0;
	rl(mask,(1<<n)-1,1){
		double p;
		int count=0;
		int tmp=mask;
		while(tmp){
			count+=tmp&1;
			tmp>>=1;
		}
		if(count==1) continue;
		p=2.0/(double)(count)/(double)(count-1);
		rb(i,1,n)
			rb(j,1,n){
				//i eats j
				if(get_mask(mask,i)&&get_mask(mask,j)){
					dp[erase_mask(mask,j)]+=dp[mask]*a[i][j]*p;
				}
			}
	}
	rep(i,n){
		printf("%.10f ",dp[1<<i]);
	}
	return 0;
}