#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int n;
ld m;
ld a[200000];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	ld ans=-1;
	int r=1;
	for (int i=1;i<=n;i++){
		r=max(r,i);
		while (r<n&&a[r+1]-a[i]<=m)r++;
		if (r-i+1>=3){
			ans=max(ans,(a[r]-a[i+1])/(a[r]-a[i]));
		}
	}
	cout<<setprecision(15)<<ans;
	return 0;
}