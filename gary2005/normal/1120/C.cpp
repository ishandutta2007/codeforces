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
int z[10020];
void z_function(string S){
//	cout<<S<<endl;
	int len=S.length();
	S='$'+S;
	int l,r;
	memset(z,0,sizeof(z));
	rb(i,2,len)
		if(S[i]!=S[i-1]) break;
		else z[2]++;
	l=2,r=z[2]+1;
	rb(i,3,len){
		if(i<=r){
			z[i]=z[i-(l)+1];
			z[i]=min(z[i],r-i+1);
			if(z[i]+i-1==r){
				int ite=z[i]+1;
				rb(j,r+1,len){
					if(S[j]!=S[ite++]) break;
					z[i]++;
				}
				l=i,r=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(S[j]!=S[ite++]) break;
				z[i]++;
			}
			l=i,r=i+z[i]-1;
		}
	}
}
int cost[5005][5005],n,a,b;
LL dp[5005]={0};
int main(){
	fastio;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	string suf;
	suf="";
	memset(cost,63,sizeof(cost));
	rb(i,2,n){
		string tmp="";
		rep(j,s.length())
		{
			if(j){
				tmp+=s[j];
			}
		}
		suf+=s[0];
		s=tmp;
		z_function(s+'&'+suf);
		int maxi=-1,Len=s.length();
		Len+=2;
		rb(j,Len,s.length()+suf.length()+1){
			maxi=max(maxi,z[j]);
		}
		rb(j,1,maxi){
//			cout<<i<<" "<<i+j-1<<endl;
			cost[i][i+j-1]=b;
		}
	}
	rb(i,1,n)
		cost[i][i]=min(cost[i][i],a);
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	rb(i,1,n){
		rb(j,0,i-1){
			dp[i]=min(dp[i],dp[j]+cost[j+1][i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}