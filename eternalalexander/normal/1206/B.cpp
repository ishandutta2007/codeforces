#include <bits/stdc++.h>
int n,t,flag=0,prd=1;
long long ans=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&t);
		int a=abs(t-1),b=abs(t+1);
		if (a<b)ans+=a;
		else {ans+=b;prd*=-1;}
		if (t==0)flag=1;
	}if (prd==1)std::cout<<ans;
	else {
		if (flag)std::cout<<ans;
		else std::cout<<ans+2;
	}
	return 0;
}