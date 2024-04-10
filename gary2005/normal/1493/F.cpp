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
int cnt=0;
vector<int> div(int n){
	vector<int> ret;
	rb(i,2,n){
		while(n%i==0){
			n/=i;
			ret.PB(i);
		}
	}
	return ret;
}
int n,m;
int query(int h,int w,int i,int j,int i2,int j2){
	cnt--;
	if(cnt==-1) while(1);
	if(max(i,i2)+h-1>n||max(j,j2)+w-1>m) while(1);
	cout<<"? "<<h<<' '<<w<<' '<<i<<' '<<j<<' '<<i2<<' '<<j2<<endl;ff;
	int a;
	cin>>a;
	return a;
}
LL rest=1;
void solve(vector<int> v,int ty){
	int cnt=1;
	if(ty==1){
		int len=n;
		int pre=-1;
		int lst=-1;
		for(auto it:v){
			if(it!=lst){
				rest*=cnt;
				cnt=1;
			}
			lst=it;
			if(pre==it) continue;
			if(it==2){
				if(query(len/2,m,1,1,1+len/2,1)){
					len/=it;
					++cnt;	
				} 
				else pre=2;
			}
			else{
				int t=len/it;
				int z=t;
				t*=it/2;
				if(query(t,m,1,1,1+t,1)&&query(t,m,1,1,1+t+z,1)){
					++cnt;
					len/=it;	
				}
				else pre=it;
			}
		}
	}
	else{
		int len=m;
		int pre=-1;
		int lst=-1;
		for(auto it:v){
			if(it!=lst){
				rest*=cnt;
				cnt=1;
			}
			lst=it;
			if(pre==it) continue;
			if(it==2){
				if(query(n,len/2,1,1,1,1+len/2)){
					len/=it;
					++cnt;	
				} 
				else pre=2;
			}
			else{
				int t=len/it;
				int z=t;
				t*=it/2;
				if(query(n,t,1,1,1,1+t)&&query(n,t,1,1,1,1+t+z)){
					len/=it;
					++cnt;	
				}
				else pre=it;
			}
		}
	}
	rest*=cnt;
}
int main(){
	cin>>n>>m;
	cnt=ceil(log(n+m)/log(2));
	cnt*=3;
//	cout<<cnt<<endl;
	solve(div(n),1);
	solve(div(m),2);
	cout<<"! "<<rest<<endl;ff;
	return 0;
}