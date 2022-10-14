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
int n,m,best[100010];
int a[100010],b[100010],t[100010];
int useless;
int main(){
	scanf("%d%d%d%d",&n,&m,&useless,&useless);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,m) scanf("%d",&b[i]);
	memset(best,63,sizeof(best));
	rb(i,1,n){
		int L,R;
		R=lower_bound(b+1,b+1+m,a[i])-b;
		L=R-1;
		if(R==m+1){
			t[i]=L;
			check_min(best[L],abs(a[i]-b[L]));
		}
		else	
		if(L==0){
			t[i]=R;
			check_min(best[R],abs(a[i]-b[R]));
		}
		else
		{
			if(abs(a[i]-b[L])==abs(a[i]-b[R])){
				if(best[L]==INF||best[L]==abs(a[i]-b[L])){
					t[i]=L;
				}
				else{
					t[i]=R;
				}
			}
			else{
				if(abs(a[i]-b[L])<abs(a[i]-b[R])){
					t[i]=L;	
				}
				else{
					t[i]=R;
				}
			}
			check_min(best[t[i]],abs(a[i]-b[t[i]]));
		}
	}
	int rest=n;
	rb(i,1,n)
		rest-=(best[t[i]]==abs(a[i]-b[t[i]]));
	cout<<rest<<endl;
	return 0;
}