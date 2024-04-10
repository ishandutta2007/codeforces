//* AuThOr GaRyMr *//
//dp[i][0][1]->to the i-th posi. and the sum %3=0,have
//dp[i][j][0]->dont have
// calc
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[100000+10][3][2];
string s;
int have_zero=0; 
void recover(int now,int res,int ans){
	int num=s[now]-'0';
	int sz=res;
	if(ans==1){
		if(num%3==res){
			cout<<s[now];
			return;
		}
		else{
			recover(now-1,res,ans);
		}
	}
	else{
		if(num%3==0){
			res-=0;
			res+=res<0? 3:0;
			if(dp[now-1][res][1]==ans-1){
				recover(now-1,res,ans-1);
				cout<<s[now];
			}
			else{
					recover(now-1,sz,ans);
				}
		}
		else{
			if(num%3==1){
				res-=1;
				res+=res<0? 3:0;
				if(dp[now-1][res][1]==ans-1){
				recover(now-1,res,ans-1);
				cout<<s[now];
				}
				else{
					recover(now-1,sz,ans);
				}
			}
			else{
				res-=2;
				res+=res<0? 3:0;
				if(dp[now-1][res][1]==ans-1){
				recover(now-1,res,ans-1);
				cout<<s[now];
				}
				else{
					recover(now-1,sz,ans);
				}
			}
		}
	}
}
int main(){
	cin>>s;
	int len=s.length();
	rep(i,len){
		dp[i][0][1]=dp[i][1][1]=dp[i][2][1]=-INF;
		dp[i][0][0]=0;
	}
	rep(i,len){
		int num=s[i]-'0';
		have_zero=have_zero|(!num);
//		cout<<num<<endl;
		if(num==0){
			if(i==0)  continue;
			dp[i][0][1]=dp[i-1][0][1]+1;
			dp[i][1][1]=dp[i-1][1][1]+1;
			dp[i][2][1]=dp[i-1][2][1]+1;
		}
		else{
			if(num%3==0){
			if(i==0){
				dp[i][0][1]=1;
				continue;
			}
				dp[i][0][1]=dp[i-1][0][1];
				dp[i][0][1]=max(dp[i][0][1],max(dp[i-1][0][1],dp[i-1][0][0])+1);
				dp[i][1][1]=dp[i-1][1][1];
				dp[i][1][1]=max(dp[i][1][1],dp[i-1][1][1]+1);
				dp[i][2][1]=dp[i-1][2][1];
				dp[i][2][1]=max(dp[i][2][1],dp[i-1][2][1]+1);
			}
			else{
				if(num%3==1){
					if(i==0){
				dp[i][1][1]=1;
				continue;
				}
					dp[i][0][1]=dp[i-1][0][1];
					dp[i][0][1]=max(dp[i][0][1],dp[i-1][2][1]+1);
					dp[i][1][1]=dp[i-1][1][1];
					dp[i][1][1]=max(dp[i][1][1],max(dp[i-1][0][1],dp[i-1][0][0])+1);
					dp[i][2][1]=dp[i-1][2][1];
					dp[i][2][1]=max(dp[i][2][1],dp[i-1][1][1]+1);
				}
				else{
					if(i==0){
				dp[i][2][1]=1;
				continue;
			}
					dp[i][0][1]=dp[i-1][0][1];
					dp[i][0][1]=max(dp[i][0][1],dp[i-1][1][1]+1);
					dp[i][1][1]=dp[i-1][1][1];
					dp[i][1][1]=max(dp[i][1][1],dp[i-1][2][1]+1);
					dp[i][2][1]=dp[i-1][2][1];
					dp[i][2][1]=max(dp[i][2][1],max(dp[i-1][0][1],dp[i-1][0][0])+1);
				}
			}
		}
//		cout<<dp[i][0][1]<<" "<<dp[i][1][1]<<" "<<dp[i][2][1]<<endl;
	}
//	int i=0;
//	cout<<dp[i][0][1]<<" "<<dp[i][1][1]<<" "<<dp[i][2][1]<<endl;
//	cout<<dp[len-1][0][1]<<" "<<-INF<<endl;
	if(dp[len-1][0][1]<=0){
		if(have_zero){
			cout<<0;
		}
		else{
			cout<<-1;
		}
	}
	else{
		recover(len-1,0,dp[len-1][0][1]);
	}
	return 0;	
}