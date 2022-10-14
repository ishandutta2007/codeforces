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
int main(){
	int n;
	cin>>n;
	vector<mp> v,u;
	rb(i,1,n){
		rb(j,1,n){
			if((i+j)&1){
				v.PB(II(i,j));
			}
			else{
				u.PB(II(i,j));
			}
		}
	}
	rb(i,1,n*n){
		int a;
		cin>>a;
		if(a!=1&&!v.empty()){
			cout<<1<<' '<<v.back().FIR<<' '<<v.back().SEC<<endl;
			v.POB();
			ff;
			continue;
		}
		if(a!=2&&!u.empty()){
			cout<<2<<' '<<u.back().FIR<<' '<<u.back().SEC<<endl;
			u.POB();
			ff;
			continue;
		}
		if(v.empty()){
			if(a==2){
				cout<<3<<' '<<u.back().FIR<<' '<<u.back().SEC<<endl;
				u.POB();
			}
			else{
				cout<<2<<' '<<u.back().FIR<<' '<<u.back().SEC<<endl;
				u.POB();
			}
		}
		else{
			if(a==1){
				cout<<3<<' '<<v.back().FIR<<' '<<v.back().SEC<<endl;
				v.POB();	
			}
			else{
				cout<<1<<' '<<v.back().FIR<<' '<<v.back().SEC<<endl;
				v.POB();
			}
		}
		ff;
	} 
	return 0;
}