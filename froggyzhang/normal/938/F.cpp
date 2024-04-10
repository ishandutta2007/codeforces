#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
char s[N];
bool dp[N][N];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	m=__lg(n);
	dp[0][0]=true;
	for(int i=0;i<n-(1<<m)+1;++i){
		for(int j=0;j<(1<<m);++j){
			if(dp[i][j]){
				for(int k=0;k<m;++k){
					if(!(j>>k&1)){
						dp[i][j|(1<<k)]=true;		
					}
				}
			}
		}
		char mn='z';
		for(int j=0;j<(1<<m);++j){
			if(dp[i][j])mn=min(mn,s[i+j+1]);
		}
		for(int j=0;j<(1<<m);++j){
			if(dp[i][j]&&mn==s[i+j+1]){
				dp[i+1][j]=true;
			}	
		}
		cout<<mn;
	}
	return 0;
}