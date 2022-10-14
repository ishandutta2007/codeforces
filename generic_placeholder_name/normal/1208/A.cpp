#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
int main() {
	int a, b, n, t; cin>>t; for(int i=1; i<=t; i++) {cin>>a>>b>>n; if(n%3==0) cout<<a<<endl; else if (n%3==1) cout<<b<<endl; else cout<<(a^b)<<endl;}
}