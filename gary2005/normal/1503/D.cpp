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
int a[200000+20],b[200000+20];
int ano[200000*2+20];
bool is[200000*2+20];
bool bad[200000*2+20];
mp gao(int l,int r,int& val){
	val=!is[l];
	int l_,r_;
	l_=l,r_=ano[l];
	int prel=l,prer=ano[l];
	bad[ano[l]]=1;
	r=r+1;
	while(l<l_||r>r_){
//		cout<<l<<' '<<r<<' '<<l_<<" "<<r_<<endl; 
		if(l<l_){
			while(l<l_){
				++l;
				if(!bad[l]){
					val+=!is[l];
					if(ano[l]>prer){
						return II(-1,-1);
					}
					bad[ano[l]]=1;
					prer=ano[l];
				}
			}
			if(prer<l_)
			return II(-1,-1);
			r_=prer;
		}
		else{
			while(r>r_){
				--r;
				if(!bad[r]){
					val+=!is[r];
					if(ano[r]<prel){
						return II(-1,-1);
					}
					bad[ano[r]]=1;
					prel=ano[r];
				}
			}
			if(prel>r_)
			return II(-1,-1);
			l_=prel;
		}
	}
	return II(l_,r_);
} 
int solve(int A,int B){
	if(A>B) return 0;
	int z=0;
	mp seg=gao(A,B,z);
	if(seg.FIR==-1) return -1;
	int cnt=B-seg.SEC+1+seg.FIR-A+1;
	int tmp=solve(seg.FIR+1,seg.SEC-1);
	if(tmp==-1) return -1;
	return tmp+min(cnt/2-z,z);
}
int main(){
	cin>>n;
	rb(i,1,n) cin>>a[i]>>b[i],ano[a[i]]=b[i],ano[b[i]]=a[i],is[a[i]]=1;
	cout<<solve(1,n+n)<<endl;
	return 0;
}