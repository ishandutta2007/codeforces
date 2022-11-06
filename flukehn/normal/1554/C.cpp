#include<bits/stdc++.h>
using namespace std;
int work(int n,int m){
	if(n>m) return 0;
	if(!m) return 1;
	if(!n) return m+1;
	int i;
	for(i=30;i>=0;--i)
		if(m>>i&1)break;
	if(m%2 && (1<<i) == m/2+1)return m+1;
	int ans=0;
	int j;
	for(j=i;j>=0;--j)
		if((n>>j&1) > (m>>j&1))
			break;
		else if((n>>j&1)<(m>>j&1))
			ans^=(1<<j);
	//cerr<<ans<<endl;
	if(j<0){
		for(int k=0;k<=i;++k){
			if(ans>>k&1)ans^=1<<k;
			if(~m>>k&1){
				ans|=1<<k;
				break;
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		cout<<work(n,m)<<"\n";
	}
}