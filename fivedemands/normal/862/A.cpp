#include<iostream>
using namespace std;
int n,x;
int sm,eq;
int a[100001];
int cnt[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	int ans=0;
	for(int i=0; i<x ;i++){
		if(cnt[i]==0) ans++;
	}
	ans+=cnt[x];
	cout << ans << endl;
}