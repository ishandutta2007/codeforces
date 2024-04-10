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
int n,a[100000+233],d[100000+233],su[100000+233];
int main(){
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		if(i==1||a[i]<a[i-1]) d[i]=1;
		else d[i]=d[i-1]+1;
	}
	int l=0;
	int cnt=0;
	rl(i,n,1){
		if(i==n||a[i]<a[i+1]) su[i]=1;
		else su[i]=su[i+1]+1;
		if(max(su[i],d[i])==l){
			cnt++;
		}
		if(max(su[i],d[i])>l)
		{
			cnt=1;
				check_max(l,max(su[i],d[i]));
		}
	}
	int rest=0;
	rb(i,1,n){
		if(d[i]==su[i]&&(d[i]&1)&&su[i]==l&&cnt==1){
			rest++; 
		}
	}
	cout<<rest<<endl;
	return 0;
}