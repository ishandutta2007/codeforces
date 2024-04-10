#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
int a[1010]={};
int main(){
	int ans=1010;
	int n=read(),m=read();
	for(int i=0;i<m;i++)a[read()]++;
	for(int i=1;i<=n;i++)ans=min(ans,a[i]);
	printf("%d",ans);
}