#include<iostream>
using namespace std;
int n,m,q;
int f[4096];
int w[4096];
int cnt[4096][101];
int wu[4096];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i=n-1; i>=0 ;i--){
		cin >> w[i];
		wu[(1<<i)]=w[i];
	}
	for(int i=0; i<(1<<n) ;i++){
		if(i!=(i&-i)) wu[i]=wu[i^(i&-i)]+wu[i&-i];
	}
	for(int i=1; i<=m ;i++){
		string s;
		cin >> s;
		int x=0;
		for(int i=0; i<n ;i++){
			x=x*2+s[i]-48;
		}
		f[x]++;
	}
	for(int i=0; i<(1<<n) ;i++){
		for(int j=0; j<(1<<n) ;j++){
			int cur=wu[(i^j)^((1<<n)-1)];
			if(cur>100) continue;
			cnt[i][cur]+=f[j];
		}
		for(int j=1; j<=100 ;j++) cnt[i][j]+=cnt[i][j-1];
	}
	for(int i=1; i<=q ;i++){
		string s;
		cin >> s;
		int x=0;
		for(int i=0; i<n ;i++){
			x=x*2+s[i]-48;
		}
		int k;
		cin >> k;
		cout << cnt[x][k] << '\n';
	}
}