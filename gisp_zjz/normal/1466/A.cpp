#include<bits/stdc++.h>
using namespace std;
int f[1000];
int _,n,ans,a[1000];
int main(){
	cin >> _;
	while (_--){
		cin >> n;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) cin >> a[i];
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				f[a[j]-a[i]]=1;
		ans=0;
		for (int i=1;i<=500;i++) ans+=f[i];
		cout << ans << endl;
	}
}