/**
 *    author:  gary
 *    created: 01.09.2021
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int tmp[4][3]={
{0,0,0},
{1,2,3},
{2,3,1},
{3,1,2}
};
void solve(){
	LL n;
	scanf("%lld",&n);
	int block=1;
	while(true){
		LL tmp=3ll*(1ll<<(2*(block-1)));
		if(tmp<n) n-=tmp;
		else break;
		block++;
	}
	LL A,B,C;
	A=B=C=0;
	rl(i,block,1){
		LL a,b,c;
		if(i==block){
			a=1,b=2,c=3;
		}
		else{
			LL T=3ll*(1ll<<(2*(i-1)));
			int z=0;
			while(T<n){
				++z;
				n-=T;
			}		
			a=tmp[z][0];
			b=tmp[z][1];
			c=tmp[z][2];
		}
		A|=a<<(2*(i-1));
		B|=b<<(2*(i-1));
		C|=c<<(2*(i-1));
	}
	if(n==1) printf("%lld\n",A);
	else if(n==2) printf("%lld\n",B);
	else printf("%lld\n",C);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();	
	return 0;
}