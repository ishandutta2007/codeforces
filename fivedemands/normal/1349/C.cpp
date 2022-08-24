#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int iu=2004;
#define fi first
#define se second
bitset<1002>b[1002],c[1002],zero,one;
int n,m,q;
vector<pair<int,pair<int,int> > >qr[2005];
int ans[100001];
void funny(){
	for(int i=1; i<=n ;i++){
		b[i][0]=b[i][1]^1;
		b[i][m+1]=b[i][m]^1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			char x;cin >> x;
			b[i][j]=x-48;
		}
	}
	for(int j=1; j<=m ;j++) one[j]=1;
	funny();
	for(int i=1; i<=q ;i++){
		int x,y;
		ll z;
		cin >> x >> y >> z;
		if(z>iu){
			if(z%2==1) z=iu-1;
			else z=iu;
		}
		qr[z].push_back({i,{x,y}});
	}
	for(int i=1; i<=iu ;i++){
		for(int i=1; i<=n ;i++){
			c[i]=b[i]^(b[i]>>1);
			c[i]&=b[i]^(b[i]<<1);
			if(i!=1) c[i]&=b[i]^b[i-1];
			if(i!=n) c[i]&=b[i]^b[i+1];
		}
		for(int i=1; i<=n ;i++){
			b[i]^=c[i]^one;
		}
		funny();
		for(auto cur:qr[i]){
			ans[cur.fi]=b[cur.se.fi][cur.se.se];
		}
	}
	for(int i=1; i<=q ;i++) cout << ans[i] << '\n';
}