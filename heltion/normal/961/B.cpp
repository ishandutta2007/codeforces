#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
int a[100010]={};
int t[100010]={};
long long s[100010]={};
int main(){
	long long sum=0;
	int n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)t[i]=read(),sum+=t[i]*a[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]*(1-t[i]);
	long long ans=0;
	for(int i=0;i+k<=n;i++)ans=max(ans,s[i+k]-s[i]);
	printf("%lld",ans+sum);
}