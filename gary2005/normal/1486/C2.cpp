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
int query(int l,int r){
	if(l==r) return 0;
	cout<<"? "<<l<<" "<<r<<endl;
	ff;
	int a;
	cin>>a;
	return a;
}
int main(){
	cin>>n;
	int b=query(1,n);
	if(b==1||query(1,b)!=b){
		//right
		int l=1,r=n-b;
		while(l<r){
			int mid=(l+r)>>1;
			if(query(b,b+mid)!=b) l=mid+1;
			else r=mid;
		}
		cout<<"! "<<l+b<<endl;
	}
	else{
		int l=1,r=b-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(query(b-mid,b)!=b) l=mid+1;
			else r=mid;
		}
		cout<<"! "<<b-l<<endl;
	}
	return 0;
}