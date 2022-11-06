#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		long long a;
		for(a=0;a<=n&&a<=10*111;a+=111){
			if((n-a)%11==0)break;
		}
		if(a>n||a>10*111)puts("NO");
		else puts("YES");
	}
}