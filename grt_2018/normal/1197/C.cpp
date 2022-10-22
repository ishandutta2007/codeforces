#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nax = 300*1000+10;
int n,k;
int a[nax],t[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n;i++) cin>>a[i];
	for(int i=2; i<=n;i++) t[i] = -a[i]+a[i-1];
	sort(t+2,t+n+1);
	ll sum = -a[1]+a[n];
	for(int i=2; i<=k; i++) sum+=t[i];
	cout<<sum;
}