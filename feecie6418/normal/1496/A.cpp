#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,k;
char str[105];
void Solve(){
	cin>>n>>k>>str+1;
	bool flag=1;
	for(int i=1;i<=k;i++)if(str[i]!=str[n-i+1])flag=0;
	if(n==2*k)flag=0;
	if(flag)puts("Yes");
	else puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}