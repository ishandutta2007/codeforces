#include<bits/stdc++.h>
#define maxn 55

using namespace std;
typedef long long ll;
ll ans,n,k,s[maxn],a[maxn],t;
bool f[maxn][maxn];

bool check(ll x){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (int i=0;i<k;i++)
		for (int j=0;j<n;j++) if (f[i][j]){
			for (int w=j+1;w<=n;w++) 
				f[i+1][w]|=((s[w]-s[j])&x)==x;
		}
	return f[k][n];
}

int main(){
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for (int i=60;i>=0;i--) if (check(ans|(1ll<<i))) ans|=(1ll<<i);
	cout << ans << endl;
	return 0;
}