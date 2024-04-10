#include<bits/stdc++.h>
using namespace std;
int work(){
	int n,m;
	cin>>n>>m;
	return 2-(n==1)-(m==1);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)cout<<work()<<"\n";
}