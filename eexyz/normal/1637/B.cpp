#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,i,fl,a[N],ans,j,k;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i){
			for(j=i;j<=n;++j){
				fl=0;
				for(k=i;k<=j;++k)ans+=1+(a[k]==0);
			}
		}
		cout<<ans<<"\n";
	}
}