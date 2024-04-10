/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
int n;
mp a[100000+20];
LL mini[100000+20];
LL dp[100000+20];
bool cmp(int A,int B){return a[A]<a[B];}
int main(){
	cin>>n;
	rb(i,1,n) cin>>a[i].FIR>>a[i].SEC;
	mp old=a[1];
	sort(a+1,a+1+n);
	LL rest=0;
	rb(i,1,n) rest+=a[i].SEC;
	mini[n+1]=1e18;
	dp[n]=0;
	mini[n]=0+a[n].FIR;
	vector<pair<int,LL>> V;
	V.PB(II(n,dp[n])); 
	rl(i,n-1,1){
		dp[i]=1e18;
		int l=i+1,r=n;
		if(a[n].FIR-a[i].FIR>a[i].SEC){
			while(l<r){
				int mid=(l+r)>>1;
				if(a[mid].FIR-a[i].FIR>a[i].SEC){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			dp[i]=mini[l]-a[i].FIR-a[i].SEC; 
		}
		else l=n+1;
		if(V.back().FIR<l){
			int L,R;
			L=0,R=V.size()-1;
			while(L<R){
				int mid=(L+R)>>1;
				if(V[mid].FIR<l) R=mid;
				else L=mid+1;
			}
			check_min(dp[i],V[L].SEC);
		}
		while(!V.empty()&&V.back().SEC>dp[i]){
			V.POB();
		}
		V.PB(II(i,dp[i]));
		if(i==1){
			rest+=dp[i];
			break;
		}
		mini[i]=min(mini[i+1],dp[i]+a[i].FIR);
	}
	cout<<rest<<endl;
	return 0;
}