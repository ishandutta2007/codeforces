#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,a[200005];long long ans=(1ll<<60),s[200005];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i=j){
		while(j<=n&&a[i]==a[j])++j;
		if(j-i>=m)ans=min(ans,0ll);
		else{
			if(j-1>=m)ans=min(ans,1ll*(a[i]-1)*(i-1)-s[i-1]+(m-(j-i)));
			if(n-i+1>=m)ans=min(ans,(s[n]-s[j-1])-1ll*(a[i]+1)*(n-j+1)+(m-(j-i)));
			ans=min(ans,1ll*(a[i]-1)*(i-1)-s[i-1]+(s[n]-s[j-1])-1ll*(a[i]+1)*(n-j+1)+(m-(j-i)));
		}
	}
	cout<<ans<<"\n";
	return 0;
}