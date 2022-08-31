#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
char s[10002],ans,ans1;
int t,n;
signed main(){
scanf("%d",&t);
while(t--){
	scanf("%d%s",&n,s+1);
	ans=ans1=0;
	for(int i=1;i<=n;++i){
		if((s[i]-'0')&1)if(!ans)ans=s[i];else ans1=s[i];
	}
	if(!ans1)puts("-1");
	else cout<<ans<<ans1<<endl;
}
}