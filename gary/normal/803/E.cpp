//* AuThOr GaRyMr *//
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
int dp[1000+10][1000+10][2];
//if 0 win-los=j; else 1 los-win=j;
string s;
void recover(int i,int j,int flag){
//	cout<<i<<"-"<<j<<"-"<<flag<<endl; 
	if(i==0) return; 
	if(j==0){
		if(s[i-1]=='W'){
			recover(i-1,1,1);
			printf("%c",s[i-1]);
			return;
		}
		if(s[i-1]=='L'){
			recover(i-1,1,0);
			printf("%c",s[i-1]);
			return;
		}
		if(s[i-1]=='D'){
			recover(i-1,0,0);
			printf("%c",s[i-1]);
			return;
		}
		if(s[i-1]=='?'){
				if(dp[i-1][1][1]){
					recover(i-1,1,1);
					printf("W");
					return;
				}
				if(dp[i-1][1][0]){
					recover(i-1,1,0);
					printf("L");
					return;
				}
				if(dp[i-1][j][0]){
					recover(i-1,j,0);
					printf("D");
				}
				return;
		}
		return;
	}
	if(s[i-1]!='?') {
		if(s[i-1]=='W'){
			 if(flag){
			 	recover(i-1,j+1,flag);
			 }
			 else{
			 	recover(i-1,j-1,0);
			 }
		}
		if(s[i-1]=='L'){
			if(flag){
				recover(i-1,j-1,flag);
			}
			else{
				recover(i-1,j+1,flag);
			}
		}
		if(s[i-1]=='D'){
		 	recover(i-1,j,flag);
		} 
		printf("%c",s[i-1]);
	}
	else{
		if(flag==0){
			if(dp[i-1][j-1][0]){
				recover(i-1,j-1,0);
				printf("W");
				return;
			}
			if(dp[i-1][j+1][0]){
				recover(i-1,j+1,0);
				printf("L");
				return;
			}
			if(dp[i-1][j][0]){
				recover(i-1,j,0);
				printf("D");
				return;
			}
		}
		else{
			if(dp[i-1][j-1][1]){
				recover(i-1,j-1,1);
				printf("L");
				return;
			}
			if(dp[i-1][j+1][1]){
				recover(i-1,j+1,1);
				printf("W");
				return;
			}
			if(dp[i-1][j][1]){
				recover(i-1,j,1);
				printf("D");
				return;
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	cin>>s;
	dp[0][0][0]=dp[0][0][1]=1;
	rb(i,1,n){
		rb(j,0,n){
			if(j==k&&i!=n) continue;
			if(s[i-1]=='W'){
				if(j>0)dp[i][j][0]=dp[i-1][j-1][0];
				dp[i][j][1]=dp[i-1][j+1][1];
			}
			if(s[i-1]=='L'){
				dp[i][j][0]=dp[i-1][j+1][0];
				if(j>0) dp[i][j][1]=dp[i-1][j-1][1];
			}
			if(s[i-1]=='D'){
				dp[i][j][0]=dp[i-1][j][0];
				dp[i][j][1]=dp[i-1][j][1];
			}
			if(s[i-1]=='?'){
				if(j>0)dp[i][j][0]=(dp[i-1][j-1][0]||dp[i][j][0]);
				else dp[i][j][0]=(dp[i-1][1][1]||dp[i][j][0]);
				dp[i][j][0]=(dp[i-1][j+1][0]||dp[i][j][0]);
				dp[i][j][0]=(dp[i-1][j][0]||dp[i][j][0]);
				
				dp[i][j][1]=dp[i-1][j+1][1];
				if(j>0) dp[i][j][1]=(dp[i][j][1]||dp[i-1][j-1][1]);
				else dp[i][j][1]=(dp[i][j][1]||dp[i-1][1][0]);
				dp[i][j][1]=(dp[i][j][1]||dp[i-1][j][1]);
			}
			if(j==0) dp[i][j][1]=dp[i][j][0]=(dp[i][j][1]||dp[i][j][0]);
		}
	}
//	cout<<dp[14][5][]<<endl;
	if(!(dp[n][k][0]||dp[n][k][1])) printf("NO\n");
	else{
		if(dp[n][k][0]){
			recover(n,k,0);
		}
		else{
			recover(n,k,1);
		}
	}
	return 0;
}