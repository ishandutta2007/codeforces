#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b[1<<20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>b[i];
	}
	int m=0;
	while((1<<m)<n)++m;
	for(int j=0;j<m;++j){
		for(int i=0;i<1<<m;++i){
			if(i>>j&1)b[i]^=b[i^(1<<j)];
		}
	}
	fill(b+n,b+(1<<m),0);
	for(int j=0;j<m;++j){
		for(int i=0;i<1<<m;++i){
			if(!(i>>j&1))b[i]^=b[i^(1<<j)];
		}
	}
	for(int i=n-1;i>=0;--i){
		cout<<b[i]<<' ';
	}
	return 0;
}