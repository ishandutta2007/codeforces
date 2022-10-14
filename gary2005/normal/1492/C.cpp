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
int n,m;
string s,t;
int pre[200000+22],suf[200000+22];
int main(){
	cin>>n>>m>>s>>t;
	s='$'+s,t='$'+t;
	rb(i,1,n){
		if(pre[i-1]==m){
			pre[i]=m;
			continue;
		}
		pre[i]=pre[i-1];
		if(t[pre[i-1]+1]==s[i]){
			pre[i]++;
		}
	}
	rl(i,n,1){
		if(suf[i+1]==m){
			suf[i]=m;
			continue;
		}
		suf[i]=suf[i+1];
		if(t[m-suf[i]]==s[i]){
			++suf[i];
		}
	}
	int r=1;
	int rest=0;
	rb(i,1,n){
		if(!pre[i]) continue;	
		check_max(r,i+1);
		while(suf[r]&&suf[r]+pre[i]>=m) ++r;
		--r;
		if(suf[r]&&suf[r]+pre[i]>=m){
			check_max(rest,r-i);
		}
	}
	cout<<rest<<endl;
	return 0;
}