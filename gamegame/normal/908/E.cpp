#include<iostream>
using namespace std;
typedef long long ll;
string s;
int cnt[1000][1000];
int m;
int n;
int size[1000];
ll c[1001][1001];
ll way[1001];
ll p2[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=1; i<=n ;i++){
		cin >> s;
		for(int j=0; j<m ;j++){
			for(int k=0; k<m ;k++){
				cnt[j][k]+=(s[j]==s[k]);
			}
		}
	}
	c[0][0]=1;
	way[0]=1;
	p2[0]=1;
	for(int i=1; i<=m ;i++){
		p2[i]=p2[i-1]*2%1000000007;
		c[i][0]=1;
		for(int j=1; j<=i ;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=1000000007;
		}
		way[i]=0;
		for(int j=0; j<i ;j++){
			way[i]=(way[i]+way[i-j-1]*c[i-1][j]);
			way[i]%=1000000007;
		}
	}
	int sets=0;
	for(int i=0; i<m ;i++){
		bool eq=false;
		for(int j=0; j<i ;j++){
			if(cnt[i][j]==n){
				size[j]++;
				break;
			}
		}
		if(!eq) size[i]=1;
	}
	long long ans=1;
	for(int i=0; i<m ;i++){
		if(size[i]==0) continue;
		ans*=way[size[i]];
		ans%=1000000007;
	}
	cout << ans << endl;
}