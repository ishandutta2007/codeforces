#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	int n,t;cin >> n >> t;
	int cur=1;
	for(int i=1; i<n ;i++) cin >> a[i];
	while(cur<t){
		cur+=a[cur];
	}
	if(cur==t )cout << "YES\n";
	else cout << "NO\n";
}