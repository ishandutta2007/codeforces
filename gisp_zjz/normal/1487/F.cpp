#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int A=200,B=330;
int dp[60][A*2+1][B*2+1],n;
string s,t;
const int inf=1e7;
void Min(int &x,int y){if (y<x) x=y;}
int main(){
	cin >> t;
	s="00000"+t;
	n=s.size();
	for (int i=0;i<=n;i++)
		for (int j=0;j<=A*2;j++)
			for (int k=0;k<=B*2;k++)
				dp[i][j][k]=inf;
    dp[0][A][B]=0;
    for (int i=0;i<n;i++)
	for (int j=-A;j<=A;j++)
	for (int k=-i*6;k<=i*6;k++){
		int res=dp[i][j+A][k+B];
		if (res==inf) continue;
		for (int l=-6;l<=6;l++){
            int nk=k+l;
            int nj=j*10+nk-(s[i]-'0');
            if (nj<-A||nj>A) continue;
            Min(dp[i+1][nj+A][nk+B],res+(n-i)*abs(l));
		}
	}
	int ans=inf;
	for (int k=-B;k<=B;k++) Min(ans,dp[n][A][k+B]);
	cout << ans << endl;
	return 0;
}