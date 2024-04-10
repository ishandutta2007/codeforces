#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int t,n,a[300005],pos,pos1;
bool ans1,ans2;
signed main(){
scanf("%d",&t);
while(t--){
	pos=pos1=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(a[i]<i-1){
			pos=i;
			break;
		}
	}
	if(!pos){
		puts("Yes");
		continue;
	}
	for(int i=n;i>=pos-1;--i){
		if(a[i]<n-i){
			pos1=i;
			continue;
		}
	}
	if(pos1)puts("No");
	else puts("Yes");
}
}