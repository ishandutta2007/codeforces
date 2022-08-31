#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int s;
int c[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> a >> b;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
		s+=c[i];
	}
	sort(c+2,c+n+1);
	int ans=0;
	while(c[1]*a/s<b){
		s-=c[n];
		n--;
		ans++;
	}
	cout << ans << endl;
}