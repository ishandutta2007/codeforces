#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1501;
int n,q;
int a[N][N];
int b[N][N][12];
int c[N][N][12];
int f[N*N];
int dp[N][N];
vector<int>delx[N],dely[N];
int col=0;
long long ans[N];
void incx(int x,int y){
	col+=++f[a[x][y]]==1;
	delx[x].push_back(a[x][y]);
}
void incy(int x,int y){
	col+=++f[a[x][y]]==1;
	dely[y].push_back(a[x][y]);
}
void del(int z){
	col-=(--f[z]==0);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;q++;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> a[i][j];
			for(int k=1; k<=q ;k++){
				b[i][j][k]=b[i][j-1][k];
			}
			for(int k=1; k<=q ;k++){
				if(a[i][b[i][j][k]]==a[i][j] || a[i][b[i][j][k]]==0 || k==q){
					b[i][j][k]=j;break;
				}
			}
			for(int k=q; k>1 ;k--){
				if(b[i][j][k]>b[i][j][k-1]) swap(b[i][j][k-1],b[i][j][k]); 
			}
			for(int k=1; k<=q ;k++){
				c[i][j][k]=c[i-1][j][k];
			}
			for(int k=1; k<=q ;k++){
				if(a[c[i][j][k]][j]==a[i][j] || a[c[i][j][k]][j]==0 || k==q){
					c[i][j][k]=i;break;
				}
			}
			for(int k=q; k>1 ;k--){
				if(c[i][j][k]>c[i][j][k-1]) swap(c[i][j][k-1],c[i][j][k]); 
			}
		}
	}/*
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cout << i << ' ' << j << ' ';
			cout << b[i][j][2] << ' ' << c[i][j][2] << endl;
		}
	}*/
	for(int k=-n+1; k<=n-1 ;k++){
		for(int i=1; i<=n ;i++){
			for(auto c:delx[i]) del(c);
			for(auto c:dely[i]) del(c);
			delx[i].clear();dely[i].clear();
		}
		//cout << "Start " << endl;
		//for(int i=1; i<=9 ;i++) cout << f[i] << ' ';
		//cout << endl;
		//cout << col << endl;
		int x,y;
		if(k<=0) x=1,y=-k+1;
		else x=k+1,y=1;
		dp[x][y]=1;
		incx(x,y);incy(x,y);
		ans[dp[x][y]]++;
		//cout << x << ' ' << y << endl;
		while(x<n && y<n){
			x++;y++;
			dp[x][y]=dp[x-1][y-1]+1;
			for(int k=1; k<=q ;k++){
				if(b[x][y][k]>y-dp[x][y]) incy(x,b[x][y][k]);
				if(c[x][y][k]>x-dp[x][y]) incx(c[x][y][k],y);
			}
			while(col>=q){
				for(auto c:delx[x-dp[x][y]+1]) del(c);
				for(auto c:dely[y-dp[x][y]+1]) del(c);
				delx[x-dp[x][y]+1].clear();dely[y-dp[x][y]+1].clear();
				dp[x][y]--;
			}
		//	cout << x << ' ' << y << ' ' << dp[x][y] << endl;
			ans[dp[x][y]]++;
		}
		
	}
	for(int i=n-1; i>=1 ;i--){
		ans[i]+=ans[i+1];
	}
	for(int i=1; i<=n ;i++) cout << ans[i] << '\n';
}