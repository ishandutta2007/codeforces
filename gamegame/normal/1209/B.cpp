#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[101],b[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=0; i<n ;i++){
		cin >> a[i] >> b[i];
	}
	int ans=0;
	for(int i=1; i<=1000 ;i++){
		int cnt=0;
		for(int j=0; j<n ;j++){
			cnt+=s[j]&1;
			if(i>=b[j] && (i-b[j])%a[j]==0) s[j]^=1;
			
		}
		ans=max(ans,cnt);
	}
	cout << ans << endl;
}