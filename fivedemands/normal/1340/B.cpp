#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
int n,k;
string w[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[2001];
int c[2001][10];
bool vis[2001][2001];
int py[2001][2001],pz[2001][2001];
void dfs(int x,int y){
	vis[x][y]=true;
	if(x==n) return;
	for(int i=9; i>=0 ;i--){
		if(c[x+1][i]<0) continue;
		int nx=x+1,ny=c[x+1][i]+y;
		if(ny>k || vis[nx][ny]) continue;
		py[nx][ny]=y;
		pz[nx][ny]=i;
		dfs(nx,ny);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> s[i];
		for(int j=0; j<10 ;j++){
			for(int k=0; k<7 ;k++){
				if(w[j][k]=='0' && s[i][k]=='1') c[i][j]=-1e9;
				else c[i][j]+=w[j][k]-s[i][k];
			}
		}
	}
	dfs(0,0);
	if(!vis[n][k]) return cout << "-1\n",0;
	string ans;
	int cx=n,cy=k;
	while(cx!=0){
		ans+=(char)('0'+pz[cx][cy]);
		cy=py[cx][cy];
		cx--;
	}
	reverse(ans.begin(),ans.end());
	cout << ans << '\n';
}