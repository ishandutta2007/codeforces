/*
{By GWj
*/
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
bool can[2];
bool check(LL s,LL e,bool turn,bool aim){
	if(aim==1){
		if(s*2>e){
			return ((e-s)&1)^turn;
		}	
		else{
			if(e&1){
				if(s*2>e/2){
					return ((e-s)&1)^turn;
				}
				else{
					if((e/2)&1){
						return check(s,e/2,turn,1);
					}
					else{
						return check(s,e/2+1,turn,1);
					}
				}
			}
			else{
				if(s*2>e/2){
					return turn^1;
				}
				else{
					return check(s,(e/2)/2,turn,1); 
				} 
			}
		}
	}
	else{
		if(s*2>e){
			return 1^turn;
		}
		else{
			return check(s,e/2,turn,1);
		}
	}
}
int main(){
	fastio;
	int t;
	R(t);
	can[0]=1;
	while(t--){
		LL s,e;
		R2(s,e);
		bool ok[2]={0};
		if(can[0]){
			ok[0]|=check(s,e,0,0);
			ok[1]|=check(s,e,0,1);
		}
		if(can[1]){
			ok[0]|=check(s,e,1,0);
			ok[1]|=check(s,e,1,1);
		}
		can[0]=ok[0];
		can[1]=ok[1];
	}
	cout<<can[1]<<" "<<can[0]<<endl;
	return 0;
}