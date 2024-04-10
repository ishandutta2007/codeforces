#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=512;
const int T=101;
int n,m;
ll a[M][M];
ll b[M][M];
int t;
int x[T],y[T];
void solve(int xl,int xr,int yl,int yr){
	if(xl==xr && yl==yr){
		b[xl][yl]=a[xl][yl];
	}
	else if(xl!=xr){
		int tm=(xr-xl+1);
		int um=(yr-yl+1);
		for(int i=xl; i<xl+tm/2 ;i++){
			for(int j=yl; j<=yr ;j++) a[i+tm/2][j]^=a[i][j];
		}
		solve(xl+tm/2,xr,yl,yr);
		for(int i=xl; i<xl+tm/2 ;i++){
			for(int j=yl; j<=yr ;j++) a[i+tm/2][j]^=a[i][j];
		}
		for(int i=xl+tm/2; i<=xr ;i++){
			for(int j=yl; j<=yr ;j++){
				for(int k=1; k<=t ;k++){
					if((i+x[k])%tm<tm/2) a[xl+(i+x[k])%tm][yl+(j+y[k])%um]^=b[i][j];
				}
			}
		}
		solve(xl,xl+tm/2-1,yl,yr);
		for(int i=xl+tm/2; i<=xr ;i++){
			for(int j=yl; j<=yr ;j++){
				for(int k=1; k<=t ;k++){
					if((i+x[k])%tm<tm/2) a[xl+(i+x[k])%tm][yl+(j+y[k])%um]^=b[i][j];
				}
				b[i][j]^=b[i-tm/2][j];
			}
		}
	}
	else{
		int tm=(xr-xl+1);
		int um=(yr-yl+1);
		for(int i=xl; i<=xr ;i++){
			for(int j=yl; j<yl+um/2 ;j++) a[i][j+um/2]^=a[i][j];
		}
		solve(xl,xr,yl+um/2,yr);
		for(int i=xl; i<=xr ;i++){
			for(int j=yl; j<yl+um/2 ;j++) a[i][j+um/2]^=a[i][j];
		}
		for(int i=xl; i<=xr ;i++){
			for(int j=yl+um/2; j<=yr ;j++){
				for(int k=1; k<=t ;k++){
					if((j+y[k])%um<um/2) a[xl+(i+x[k])%tm][yl+(j+y[k])%um]^=b[i][j];
				}
			}
		}
		solve(xl,xr,yl,yl+um/2-1);
		for(int i=xl; i<=xr ;i++){
			for(int j=yl+um/2; j<=yr ;j++){
				for(int k=1; k<=t ;k++){
					if((j+y[k])%um<um/2) a[xl+(i+x[k])%tm][yl+(j+y[k])%um]^=b[i][j];
				}
				b[i][j]^=b[i][j-um/2];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;m=1<<n;
	for(int i=0; i<m ;i++){
		for(int j=0; j<m ;j++){
			cin >> a[i][j];
		}
	}
	cin >> t;
	for(int i=1; i<=t ;i++){
		cin >> x[i] >> y[i];
	}
	solve(0,m-1,0,m-1);
	int ans=0;
	for(int i=0; i<m ;i++){
		for(int j=0; j<m ;j++){
			ans+=(b[i][j]!=0);
		}
	}
	cout << ans << '\n';
}