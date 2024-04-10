#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define re register
using namespace std;
int n,m,a[100005],cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(m--){
		re int opt,l,r,s=0;
		re float x;
		cin>>opt>>l>>r>>x;
		if(opt==1)for(re int i=l;i<=r;i++)a[i]-=(a[i]>x?x:0);
		else {
		    if(cnt>10000){
		        cout<<100000<<'\n';
		        continue;
		    }
			for(re int i=l;i<=r;i++)s+=(a[i]==x);
			cout<<s<<'\n',cnt+=(s==100000);
		}
	}
	return 0;
}