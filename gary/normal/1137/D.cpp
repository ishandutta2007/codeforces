/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int result(){
	int res;
	cin>>res;
	int a;
	rb(i,1,res) cin>>a;
	return res;
}
int main(){
	fastio;
	int TT=0;
	while(1){
		TT++;
	  	cout<<"next 0 1\n";
	  	ff;
	  	result();
		cout<<"next 1\n";
		ff;
		int tmp=result();
		if(tmp==2){
			break ;// 0 & 1 both on the cycle 
		}
	}
	int len=0;
	while(1){
		len++;
		cout<<"next 1\n";
		ff;
		int tmp=result();
		if(tmp==2){
			break;
		}
	}
	TT%=len;
	if(TT==0) TT=len;
	len-=TT;
	rb(i,1,len)
		cout<<"next 0 1\n",ff,result();	
	while(1){
		cout<<"next 2 3 0 1 4 5 6 7 8 9\n",ff;
		if(result()==1){
			cout<<"done\n";
			break;
		}
	}
	return 0;
}