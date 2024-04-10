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
void query(int l,int r,int pos){
	if(l==r){
		cout<<"! "<<l<<endl;
		exit(0);
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		int ret=query(l,mid);
		if(ret==pos&&mid!=l){
			query(l,mid,ret);
			return ;
		}
		query(mid+1,r,query(mid+1,r));
	}
	else{
		 int ret=query(mid+1,r);
		 if(ret==pos&&mid+1!=r){
		 	query(mid+1,r,ret);
		 	return ;
		 }
		 query(l,mid,query(l,mid));
	}
}
int main(){
	cin>>n;
	query(1,n,query(1,n));
	return 0;
}