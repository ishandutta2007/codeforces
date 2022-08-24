#include<iostream>
#include<unordered_map>
using namespace std;
int a[100001],b[100002];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> b[i];
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		int l=1,r=m,mid;
		while(l!=r){
			mid=(l+r)/2;
			if(b[mid]<a[i]){
				l=mid+1;
			}
			else r=mid;
		}
		if(b[l]<a[i]) ans=max(ans,a[i]-b[l]);
		else if(r!=1) ans=max(ans,min(a[i]-b[l-1],b[r]-a[i]));
		else ans=max(ans,b[1]-a[i]);
	}
	cout << ans << endl;
}