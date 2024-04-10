#include <bits/stdc++.h>
#define ll long long
int base=400002;
int n,b;
ll vis[800005],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&b);
		vis[base+b-i]+=b;
		ans=std::max(ans,vis[base+b-i]);
	}std::cout<<ans;
	return 0;
}