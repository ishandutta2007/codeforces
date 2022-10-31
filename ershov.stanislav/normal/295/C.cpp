#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

#define mod 1000000007

long long n, kk, c50, c100, dp[55][55], dp2[55][55], c[55][55];
bool open[55][55][2];

int main() {
	cin >> n >> kk;
	c[0][0]=1;
	for (int i=0; i<55; i++) {
		c[i][0]=c[i][i]=1;
		for (int j=1; j<i; j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		if (a==50) c50++;
		else c100++;
	}
	dp[c50][c100]=1;
	open[c50][c100][1]=true;
	bool change=true;
	int k=0;
	while (change) {
		change=false;
		for (int i=0; i<=c50; i++) for (int j=0; j<=c100; j++) dp2[i][j]=0;
		for (int i=0; i<=c50; i++) for (int j=0; j<=c100; j++) {
			if (k%2) {
				for (int ii=i; ii<=c50; ii++) {
					for (int jj=j; jj<=c100; jj++) if (ii!=i||jj!=j){
						if ((i-ii)*50+(j-jj)*100<-kk) break;
						long long inc=dp[i][j];
						inc=(inc*c[c50-i][ii-i])%mod;
						inc=(inc*c[c100-j][jj-j])%mod;
						dp2[ii][jj]+=inc;
						dp2[ii][jj]%=mod;
						if (!open[ii][jj][k%2]&&open[i][j][(k%2)^1])open[ii][jj][k%2]=true, change=true;
					}
					if ((ii-i)*50>kk) break;
				}
			} else {
				for (int ii=i; ii>=0; ii--) {
					for (int jj=j; jj>=0; jj--) if (ii!=i||jj!=j){
						if ((i-ii)*50+(j-jj)*100>kk) break;
						long long inc=dp[i][j];
						inc=(inc*c[i][ii])%mod;
						inc=(inc*c[j][jj])%mod;
						dp2[ii][jj]+=inc;
						dp2[ii][jj]%=mod;
						if (!open[ii][jj][k%2]&&open[i][j][(k%2)^1])open[ii][jj][k%2]=true, change=true;
					}
					if ((i-ii)*50>kk) break;
				}
			}
		}
		for (int i=0; i<=c50; i++) for (int j=0; j<=c100; j++) dp[i][j]=dp2[i][j];
		if (dp[0][0]) {
			cout << k+1 << ' ' << dp[0][0];
			return 0;
		}
		k++;
	}
	cout << -1 << ' ' << 0;
	return 0;
}