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
int work(string s){
	int A=0,B=0;
	rep(i,s.length()){
		int rst=s.length()-i;
		if(A>B){
			if(A>B+(rst+1)/2){
				return i;
			}
		}
		if(A<B){
			if(A+rst/2<B){
				return i;
			}
		}
		if(s[i]=='1'){
			if(i&1) B++;
			else A++;
		}
	}
	return 10;
}
int solve1(string s){
	rep(i,s.length()){
		if(s[i]=='?'){
			if(i&1) s[i]='1';
			else s[i]='0';
		}
	}
	return work(s);
}
int solve2(string s){
	rep(i,s.length()){
		if(s[i]=='?'){
			if(i&1) s[i]='0';
			else s[i]='1';
		}
	}
	return work(s);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		cout<<min(solve1(s),solve2(s))<<endl;
	}
	return 0;
}