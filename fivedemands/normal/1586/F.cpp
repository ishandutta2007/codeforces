#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int ans[1001][1001];
int n,k;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	int cur=1;
	int c=0;
	while(cur<n){
		c++;
		cur*=k;
	}
	cout << c << '\n';
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			int u=i-1;
			int v=j-1;
			for(int z=0; z<c ;z++){
				if(u%k!=v%k) ans[i][j]=z+1;
				u/=k;v/=k;
			}
			cout << ans[i][j] << ' ';
		}
		
	}
	cout << '\n';
}