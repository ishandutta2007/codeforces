#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s[100005],ret=1e9;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	a[n+1]=2e9;
	if(n>100)return puts("1"),0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k;l<=n;l++){
					if((s[l]^s[k-1])<(s[j]^s[i-1]))ret=min(ret,l-k+j-i);
				}
			}
		}
	}
	if(ret>1e8)puts("-1");
	else cout<<ret;
	return 0;
}