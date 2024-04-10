#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int f[maxn];
int _,n,ans,a[maxn];
int main(){
	cin >> _;
	while (_--){
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
        for (int i=1;i<=n*2+1;i++) f[i]=0;
		for (int i=1;i<=n;i++) {
			if (f[a[i]]) a[i]++;
			f[a[i]]=1;
		}
        ans=0;
        for (int i=1;i<=n*2+1;i++) ans+=f[i];
		cout << ans << endl;
	}
}