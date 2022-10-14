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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+20;
int n,k; 
int a[MAXN],d[MAXN];
LL suf[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) scanf("%d",&d[i]);
	LL rest=0;
	if(k==0){
		LL sum=0;
		rl(i,n,1){
			sum+=a[i];
			check_max(rest,sum-d[i]);
		}
	}
	else{
		if(k==1){
			LL sum=0;
			rl(i,n,2){
				sum+=a[i];
				check_max(rest,sum-d[i]);
			}
			rl(i,n,1)
				suf[i]=suf[i+1]+a[i];
			rl(i,n,1)
				suf[i]=max(suf[i+1],suf[i]-d[i]);
			check_max(rest,sum+a[1]-a[2]-d[1]);
			check_max(rest,sum+a[1]-a[n-1]-d[1]);
			sum-=a[n];
			sum+=a[1];
			int mini=INF;
			LL ssm=0;
			LL mi=INF;
			rb(i,1,n-1){
				check_min(mi,(LL)d[i]);
				ssm+=a[i];
				check_max(rest,ssm-mi+suf[i+1]);
			}
			rb(i,1,n-1)
				check_min(mini,d[i]);
			check_max(rest,sum-mini);
			mini=INF;
			rb(i,2,n){
				check_min(mini,a[i]);
			}
			check_max(rest,sum+a[n]-d[1]-mini);
			sort(d+1,d+n);
			check_max(rest,sum+a[n]-d[1]-d[2]);
		}
		else{
			LL sum=0;
			rl(i,n,1){
				sum+=a[i];
				check_max(rest,sum-d[i]);
			}
//			4 1
//10 10 9 100
//1 10 10 1000000
			int mini=INF;
			rb(i,1,n-1){
				check_min(mini,d[i]);
			}
			check_max(rest,sum-mini);
		}
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  * k=0 
  	k=1,1n-1ai-di/0/
	 else   max(0,A1+...An - min(Di,(i!=n)) ) 
  * 
  *
  **/