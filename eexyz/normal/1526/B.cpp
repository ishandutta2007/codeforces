#include<bits/stdc++.h>
using namespace std;
#define pn cout<<"NO\n";
#define py cout<<"YES\n";
int T,n,i,j,fl,a[1005];
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=fl=0;i<100;++i){
			if(i*111<=n&&(n-i*111)%11==0)fl=1;
		}
		if(fl)py
		else pn
	}
}