#include<iostream>
using namespace std;
int n;
long long k;
long long sum[100000][34];
long long mini[100000][34];
long long ff[100000][34];
long long w[100000];
long long f[100000];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<n ;i++){
		cin >> f[i];
		ff[i][0]=f[i];
	}
	for(int i=0; i<n ;i++){
		cin >> w[i];
		sum[i][0]=mini[i][0]=w[i];
	}
	for(int i=1; i<=33 ;i++){
		for(int j=0; j<n ;j++){
			ff[j][i]=ff[ff[j][i-1]][i-1];
			mini[j][i]=min(mini[j][i-1],mini[ff[j][i-1]][i-1]);
			sum[j][i]=sum[j][i-1]+sum[ff[j][i-1]][i-1];
		}
	}
	for(int i=0; i<n ;i++){
		int cur=i;
		long long s=0,m=2e9;
		for(int j=0; j<=33 ;j++){
			if(k&(1LL<<j)){
				s+=sum[cur][j];
				m=min(m,mini[cur][j]);
				cur=ff[cur][j];
			}
		}
		cout << s << ' ' << m << '\n';
	}
}