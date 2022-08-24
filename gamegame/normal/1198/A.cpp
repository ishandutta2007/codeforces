#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[400001];
map<int,int>fr;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	k=k*8/n;
	if(k>=30) k=30;
	for(int i=1; i<=n ;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int r=1;
	fr[a[1]]++;
	int ans=n;
	for(int i=1; i<=n ;i++){
		while(r<n && fr.size()<=(1<<k)){
			r++;fr[a[r]]++;
		}
		if(fr.size()<=(1<<k)) ans=min(ans,n-r+i-1);
		else ans=min(ans,n-r+i);
		fr[a[i]]--;
		if(fr[a[i]]==0) fr.erase(a[i]);
	}
	cout << ans << endl;
}