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
const int MAXN=1e5+10;
int a[MAXN],m,can[MAXN];
string s;
int dp[MAXN][1<<6],cnt[6];
bool check(int index){
	rep(mask,1<<6){
		int have=0;
		rep(i,6){
			if((mask>>i)&1){
				have+=cnt[i];
			}
		}
		if(have<dp[index][mask]){
			return false;
		}
	}
	return true;
}
int main(){
	fastio;
	cin>>s;
	int n=s.length();
	rep(i,s.length())
		a[i+1]=s[i]-'a',cnt[a[i+1]]++;
//	rep(i,6) cout<<cnt[i]<<endl; 
	R(m);
	rb(i,1,m){
		int pos;
		string s;
		R2(pos,s);
		rep(j,s.length()){
			can[pos]|=1<<(s[j]-'a');
		}
	}
	rb(i,1,n) if(!can[i]) can[i]=(1<<6)-1;
	rl(i,n,1){
		rep(mask,1<<6){
			check_max(dp[i][mask],dp[i+1][mask]);
			check_max(dp[i][mask|can[i]],dp[i+1][mask]+1);
		}
	}
//	cnt[0]--;
//	check(2);
	string rest="";
	if(!check(1)){
		cout<<"Impossible\n";
		return 0;
	}
	rb(i,1,n){
		rep(j,6){
			if((can[i]>>j)&1)
			if(cnt[j]){
				cnt[j]--;
				if(!check(i+1)){
					cnt[j]++;
				}
				else{
					rest+=char('a'+j);
					break;
				}
			}
		}
	}
	cout<<rest<<endl;
	return 0;
}