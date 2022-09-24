#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int c[10],a[10],flag=1;
		for(int i=1;i<=3;i++)cin>>c[i];
		for(int i=1;i<=5;i++)cin>>a[i];
		c[1]-=a[1],c[2]-=a[2],c[3]-=a[3];
		for(int i=1;i<=3;i++)if(c[i]<0)flag=0;
		int t=min(a[4],c[1]);
		a[4]-=t,c[1]-=t,c[3]-=a[4];
		t=min(a[5],c[2]);
		a[5]-=t,c[2]-=t,c[3]-=a[5];
		if(c[3]<0)flag=0;
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}