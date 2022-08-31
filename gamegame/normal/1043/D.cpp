#include<iostream>
using namespace std;
typedef long long ll;
int n,m;
int cnt[100001];
int a[11][100001];
int prv[11][100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		for(int j=1; j<=n ;j++) cin >> a[i][j];
		for(int j=1; j<=n ;j++){
			prv[i][a[i][j]]=a[i][j-1];
		}
	}
	for(int i=1; i<=n ;i++){
		int cur=a[1][i];
		int last=a[1][i-1];
		bool ok=true;
		for(int j=1; j<=m ;j++){
			if(prv[j][cur]!=last) ok=false;
		}
		if(ok) cnt[cur]=cnt[last]+1;
		else cnt[cur]=1;
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans+=cnt[i];
	}
	cout << ans << endl;
}