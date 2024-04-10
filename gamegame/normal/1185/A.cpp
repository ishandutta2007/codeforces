#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	ll a[3];
	for(int i=0; i<3 ;i++) cin >> a[i];
	ll d;cin >> d;
	sort(a,a+3);
	cout << max(d-a[1]+a[0],0LL)+max(d-a[2]+a[1],0LL);
}