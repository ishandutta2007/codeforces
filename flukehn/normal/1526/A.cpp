#include<bits/stdc++.h>
using namespace std;
int a[222],n;
int chk(){
	a[0]=a[n];
	a[n+1]=a[1];
	for(int i=1;i<=n;++i){
		if(a[i]*2==a[i-1]+a[i+1])return 0;
	}
	return 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	srand(time(0));
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		n<<=1;
		for(int i=1;i<=n;++i)cin>>a[i];
		do{
			random_shuffle(a+1,a+n+1);
		}while(!chk());
		for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
	}
}