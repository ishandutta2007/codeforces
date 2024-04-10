#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,i,fl,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		fl=1;
		for(i=1;i<n;++i)if(a[i]>a[i+1])fl=0;
		if(!fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
}