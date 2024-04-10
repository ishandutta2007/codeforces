#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
int n,m,z;
char c[502][502];
bool d[502][502];
ll p[502][502];
ll f[502];
ll pf[502];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> z;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> c[i][j];
		}
	}
	for(int i=2; i<n ;i++){
		for(int j=2; j<m ;j++){
			p[i][j]=p[i-1][j]+d[i][j];
			if(c[i][j]!='1') continue;
			if(c[i-1][j]!='1') continue;
			if(c[i+1][j]!='1') continue;
			if(c[i][j-1]!='1') continue;
			if(c[i][j+1]!='1') continue;
			d[i][j]=true;
			p[i][j]=p[i-1][j]+d[i][j];
		}
	}
	ll ans =0;
	for(int i=2; i<=n-1 ;i++){
		for(int j=i; j<=n-1 ;j++){
			int l=1;
			for(int k=2; k<=m-1 ;k++){
				f[k]=p[j][k]-p[i-1][k];
				pf[k]=pf[k-1]+f[k];
				while(pf[k]-pf[l]>=z) l++;
				ans+=l-1;
				//cout << f[k] << endl;
			}
			//cout << i << ' ' << j << ' ' << ans << '\n';
		}
	}
	cout << ans << endl;
}