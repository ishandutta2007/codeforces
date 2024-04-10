#include<iostream>
using namespace std;
int n;
int a[201],b[201],c[201];
bool vis[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=2*n ;i++){
		cin >> a[i];
		if(b[a[i]]==0) b[a[i]]=i;
		else c[a[i]]=i;
	}
	int ans=0;
	for(int i=1; i<=2*n ;i++){
		if(vis[a[i]]) continue;
		vis[a[i]]=true;
		int d=c[a[i]];
		ans+=d-i-1;
		for(int j=d-1; j>i ;j--){
			if(b[a[j]]==j) b[a[j]]=j+1;
			else c[a[j]]=j+1;
			swap(a[j],a[j+1]);
		}
	}
	cout << ans << endl;
}