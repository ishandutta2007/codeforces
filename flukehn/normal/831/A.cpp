#include<bits/stdc++.h>
using namespace std;
int n,a[110];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int ans=0;
	a[0]=a[n+1]=-1000000;
	int i=1;
	for(i=1;a[i]>a[i-1]&&i<=n;i++);
	for(;a[i]==a[i-1]&&i<=n;i++);
	for(;a[i]<a[i-1]&&i<=n;i++);
	puts(i==n+1?"YES":"NO");
}