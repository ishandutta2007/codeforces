#include<bits/stdc++.h>
using namespace std;
int T,n,k,i,j;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(k>(n+1)/2){
			cout<<"-1\n";
		}
		else{
			for(i=1;i<=n;++i){
				for(j=1;j<=n;++j){
					if(i==j&&(i&1)&&(i<=k+k))cout<<'R';
					else cout<<'.';
				}cout<<"\n";
			}
		}
	}
}