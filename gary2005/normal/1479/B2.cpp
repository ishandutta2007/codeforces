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
int a[100000+233];
int f[100003],g[100003];
int pre[100003];
int pre2[100003];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	vector<int> v;
	rb(i,1,n) if(a[i]!=a[i-1]) v.PB(a[i]);
	n=v.size();
	memset(pre,-63,sizeof(pre));
	memset(pre2,-63,sizeof(pre2));
	rb(i,1,n) a[i]=v[i-1];
//	cout<<n<<endl;
//	rb(i,1,n){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	int maxi=-INF,maxi2=-INF;
	rb(i,1,n){
		if(i>=3){
			check_max(maxi,g[i-2]);
			check_max(pre[a[i-2]],g[i-2]);
		}
		f[i]=maxi;
		check_max(f[i],pre[a[i]]+1);
		check_max(maxi2,f[i]);
		check_max(pre2[a[i-1]],f[i]);
		check_max(g[i],maxi2);
		if(i!=n)
			check_max(g[i],pre2[a[i+1]]+1);
//		cout<<f[i]<<" "<<g[i]<<endl;
	}
	int rest=0;
	rb(i,1,n) check_max(rest,g[i]);
	cout<<n-rest<<endl;
	return 0;
}