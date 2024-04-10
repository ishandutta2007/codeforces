/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
mp rest;
int a[101][101];
int n,m,k;
int main(){
	rest=II(0,0);
	scanf("%d%d%d",&n,&m,&k);
	rb(i,1,n)
	rb(j,1,m) cin>>a[i][j];
	rb(j,1,m){
		mp tmp=II(0,0);
		mp tmptmp=II(0,0);
		vector<int> v;
		rb(i,1,n) if(a[i][j]) v.PB(i);
		int z=0;
		int h=0;
		for(auto it:v){
			while(z<v.size()&&v[z]-it<k){
				++z;
			}
			tmptmp.FIR=z-h;
			check_max(tmp,tmptmp);
			tmptmp.SEC--;
			++h;
		}
		rest.FIR+=tmp.FIR;
		rest.SEC+=tmp.SEC;
	}
	cout<<rest.FIR<<' '<<-rest.SEC<<endl;	
	return 0;
}