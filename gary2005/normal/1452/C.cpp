/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
vector<char> v1,v2;

int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		v1.clear();
		v2.clear();
		string s;
		cin>>s;
		rep(i,s.length()){
			if(s[i]=='['||s[i]==']'){
				v1.PB(s[i]); 
			} 
			else{
				v2.PB(s[i]);
			}
		}
		int rest=0;
		int cnt=0;
		for(auto it:v1){
			if(it==']'){
				if(cnt){
					cnt--;
					rest++;
				}
			}
				else{
					cnt++;
				}
		}
		cnt=0;
		for(auto it:v2){
			if(it==')'){
				if(cnt){
					cnt--;
					rest++;
				}
			}
				else{
					cnt++;
				}
		}
		cout<<rest<<endl;
	}	
	return 0;
}