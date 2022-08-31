#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll a[1000001];
int f[200001];
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n ;i++) f[i]=0;
		int c=0;
		for(int i=1; i<=n ;i++){
			cin >> a[i];
			f[a[i]]++;
			if(f[a[i]]==1) c++;
		}
		int ans=0;
	//	cout << c << endl;
		for(int i=1; i<=n ;i++){
			if(f[i]==0) continue;
			if(f[i]>c) ans=max(ans,c);
			else if(f[i]<c) ans=max(ans,f[i]);
			else ans=max(ans,c-1);
		}
		cout << ans << '\n';
	}
}