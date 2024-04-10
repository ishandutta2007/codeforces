#include<iostream>
#include<vector>
using namespace std;
int n;
int s[200001],g[200001];
int mini[200001],maxi[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> s[i] >> g[i];
	}
	mini[1]=s[1],maxi[1]=s[1]+g[1];
	for(int i=2; i<=n ;i++){
		mini[i]=max(mini[i-1]-1,s[i]);
		maxi[i]=min(maxi[i-1]+1,s[i]+g[i]);
		if(mini[i]>maxi[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	long long ans=maxi[n]-s[n];
	for(int i=n-1; i>=1 ;i--){
		mini[i]=max(mini[i],mini[i+1]-1);
		maxi[i]=min(maxi[i],maxi[i+1]+1);
		if(mini[i]>maxi[i]){
			cout << -1 << endl;
			return 0;
		}
		ans+=maxi[i]-s[i];
	}
	cout << ans << endl;
	for(int i=1; i<=n ;i++){
		cout << maxi[i] << ' ';
	}
	cout << endl;
}