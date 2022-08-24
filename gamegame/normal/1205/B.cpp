#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m=62;
bool hv[64][64];
ll a[100001];
int cnt[64];
vector<int>b[64];
bool vis[64];
int d[128][128],w[128][128];
map<int,int>mp;
int q=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		for(int j=m; j>=0 ;j--){
			if(a[i]&(1LL<<j)) b[j].push_back(i);
		}
	}
	for(int i=1; i<=2*m ;i++){
		for(int j=1; j<=2*m ;j++){
			d[i][j]=1e8;
			w[i][j]=1e8;
		}
		d[i][i]=w[i][i]=0;
	}
	for(int j=0; j<m ;j++){
		if(b[j].size()>2){
			cout << "3\n";
			return 0;
		}
		if(b[j].size()<2) continue;
		int x=b[j][0],y=b[j][1];
		if(!mp[x]) mp[x]=++q;
		if(!mp[y]) mp[y]=++q;
		x=mp[x],y=mp[y];
		d[x][y]=d[y][x]=w[x][y]=w[y][x]=1;
	}
	int ans=1e8;
	for(int i=1; i<=q ;i++){
		for(int j=1; j<i ;j++){
			for(int k=j+1; k<i ;k++){
				ans=min(ans,w[i][j]+d[j][k]+w[k][i]);
			}
		}
		for(int j=1; j<=q ;j++){
			for(int k=1; k<=q ;k++){
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	if(ans!=1e8) cout << ans << endl;
	else cout << -1 << endl;
}