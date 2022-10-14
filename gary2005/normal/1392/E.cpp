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

int n; 
LL a[27][27];
int main(){
	fastio;
	R(n);
	int shift=n-1;
	rb(i,1,n)
	{
		LL now=(1ll<<shift);
		vector<LL> vv;
		rl(j,n,1){
			if(i&1){
				vv.PB(0);
			}
			else{
				vv.PB(now);
				now>>=1;
			}
		}
		reverse(ALL(vv));
		int j=1;
		for(auto it:vv){
			cout<<it<<" ";
			a[i][j++]=it;
		}
		cout<<endl;
		if(i&1);
		else shift+=2;
	}
	cout<<endl;
	ff;
	int q;
	R(q);
	rb(Q,1,q){
		LL k;
		R(k);
		vector<mp> way;
		int las=1;
		rb(i,1,n){
			if(i&1);
			else{
				int las_las=las;
				while(!(k&(a[i][las]))){
					las++;
				}
				rb(j,las_las,las){
					way.PB(II(i-1,j));
				}
				while(k&(a[i][las])){
					way.PB(II(i,las));
					las++;
				}
				las--;
			}
		}
		if(n&1){
			rb(j,las,n)
				way.PB(II(n,j));
		}
		for(auto it:way){
			cout<<it.FIR<<" "<<it.SEC<<endl;
		}
		cout<<endl;
		ff;
		
	}
	return 0;
}
/*
*/