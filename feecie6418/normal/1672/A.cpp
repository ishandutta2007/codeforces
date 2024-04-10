#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n;
void Solve(){
	cin>>n;
	int s=0;
	for(int i=1,x;i<=n;i++)cin>>x,s+=x-1;
	if(s&1)puts("errorgorn");
	else puts("maomao90");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}