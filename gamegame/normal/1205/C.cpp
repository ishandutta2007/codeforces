#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[2][51][51];
int dx[6]={0,1,2,0,-1,-2},dy[6]={2,1,0,-2,-1,0};
int qry(int x1,int y1,int x2,int y2){
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int res;cin >> res;return res;
}
void pass(int x1,int y1,int x2,int y2,int z){
	a[0][x2][y2]=a[0][x1][y1]^z^1;
	a[1][x2][y2]=a[1][x1][y1]^z^1;
}
int check(int x,int y,int z){
	if(a[z][x][y]!=a[z][x+2][y+1]) return false;
	if(a[z][x+1][y]==a[z][x+2][y]) return true;
	if(a[z][x+1][y]==a[z][x+1][y+1]) return true;
	if(a[z][x][y+1]==a[z][x+1][y+1]) return true;
	return false;
}
int check2(int x,int y,int z){
	if(a[z][x][y]!=a[z][x+1][y+2]) return false;
	if(a[z][x+1][y]==a[z][x+1][y+1]) return true;
	if(a[z][x][y+1]==a[z][x+1][y+1]) return true;
	if(a[z][x][y+1]==a[z][x][y+2]) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<2 ;i++) a[i][1][1]=1;
	for(int i=0; i<2 ;i++) a[i][n][n]=0;
	a[0][1][2]=1;a[1][1][2]=0;
	pass(1,1,2,2,qry(1,1,2,2));
	pass(1,2,2,3,qry(1,2,2,3));
	pass(1,1,1,3,qry(1,1,1,3));
	pass(2,3,2,1,qry(2,1,2,3));
	for(int i=4; i<=n ;i++){
		pass(1,i-2,1,i,qry(1,i-2,1,i));
		pass(2,i-2,2,i,qry(2,i-2,2,i));
	}
	for(int i=3; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(i==n && j==n) continue;
			pass(i-2,j,i,j,qry(i-2,j,i,j));
		}
	}
	int ans=2;
	for(int i=1; i<=n ;i++){
		if(ans!=2) break;
		for(int j=1; j<=n ;j++){
			if(ans!=2) break;
			if(i+2<=n && j+1<=n){
				bool res0=check(i,j,0);
				bool res1=check(i,j,1);
				if(res0!=res1){
					int val=qry(i,j,i+2,j+1);
					ans=(val!=res0);
					break;
				}
			}
			if(i+1<=n && j+2<=n){
				bool res0=check2(i,j,0);
				bool res1=check2(i,j,1);
				if(res0!=res1){
					int val=qry(i,j,i+1,j+2);
					ans=(val!=res0);
					break;
				}
			}
			if(ans!=2) break;
		}
		if(ans!=2) break;
	}
	if(ans==2) while(true);
	cout << "!\n";
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++) cout << a[ans][i][j];
		cout << endl;
	}
}