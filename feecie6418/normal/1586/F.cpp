#include<bits/stdc++.h>
using namespace std;
int K,n; 
int main(){
	cin>>n>>K;
	cout<<(int)ceil(log(n)/log(K))<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p=i-1,q=j-1,c=1,ans=0;
			while(p||q){
				if(p%K!=q%K)ans=c;
				q/=K,p/=K,c++;
			}
			cout<<ans<<' ';
		}
	}
}