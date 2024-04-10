#include<bits/stdc++.h>
#define pc __builtin_popcountll
using namespace std;
typedef long long ll;
int n,m,q;
ll dp[9][9];
char c[1001][1001];
ll pf[1001][1001];
void funny(){
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+c[i][j]-48;
		}
	}
}
ll qr(ll x,ll y){
	ll rx=x/n;
	ll ry=y/m;
	ll sx=x-rx*n;
	ll sy=y-ry*m;
	ll p1=0,p2=0,p3=0,p4=0;
	if(pc(rx^ry)%2){
		p1=sx*sy-pf[sx][sy];
	}
	else{
		p1=pf[sx][sy];
	}
	if(rx%2==0) p2=n*sy*rx/2;
	else if(pc((rx-1)^ry)%2){
		p2=n*sy*(rx-1)/2+n*sy-pf[n][sy];
	}
	else{
		p2=n*sy*(rx-1)/2+pf[n][sy];
	}
	if(ry%2==0) p3=m*sx*ry/2;
	else if(pc((ry-1)^rx)%2){
		p3=m*sx*(ry-1)/2+m*sx-pf[sx][m];
	}
	else{
		p3=m*sx*(ry-1)/2+pf[sx][m];
	}
	if(rx%2==0 || ry%2==0) p4=n*m*rx*ry/2;
	else if(pc((rx-1)^(ry-1))%2){
		p4=n*m*(rx*ry-1)/2+n*m-pf[n][m];
	}
	else{
		p4=n*m*(rx*ry-1)/2+pf[n][m];
	}
	//cout << "qr " << x << ' ' << y << ' ' << p1+p2+p3+p4 << ' ' << dp[x][y] << endl;
	//cout << p1 << ' ' << p2 << ' ' << p3 << ' ' << p4 << endl;
	return p1+p2+p3+p4;
}
string ds="1100001101101001001111001001011000111100100101101100001101101001";

ll funy(){
	for(int i=1; i<=8 ;i++){
		for(int j=1; j<=8 ;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+ds[(j-1)*8+(i-1)]-'0';
		}
	}
}
ll debug(ll x,ll y){
	return dp[x][y];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
		}
	}
	funny();funy();
	for(int i=1; i<=q ;i++){
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;x1--;y1--;
		cout << qr(x2,y2)+qr(x1,y1)-qr(x1,y2)-qr(x2,y1) << '\n';
	}
}