#include<bits/stdc++.h>
using namespace std;
#define N 1024
typedef long long ll;
int n,k,x,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>x;
	for(int i=1;i<=n;++i){
		int z;
		cin>>z;
		++a[z];
	}
	while(k--){
		static int b[N];
		for(int i=0;i<1024;++i)b[i]=0;
		for(int i=0,jb=0;i<1024;++i){
			b[i^x]+=a[i]/2;
			b[i]+=a[i]/2;
			if(a[i]&1){
				jb&1?++b[i]:++b[i^x];
				jb^=1;
			}
		}
		swap(a,b);
	}
	for(int i=1023;i>=0;--i){
		if(a[i]){cout<<i<<' ';break;}
	}
	for(int i=0;i<1024;++i){
		if(a[i]){cout<<i<<'\n';break;}
	}
	return 0;
}