#include <bits/stdc++.h>
using namespace std;
signed main(){
	int a[10],s=0;
	for(int i=1;i<=6;i++)cin>>a[i],s+=a[i];
	if(s%2)return puts("NO"),0;
	s/=2;
	for(int i=1;i<=4;i++){
		for(int j=i+1;j<=5;j++){
			for(int k=j+1;k<=6;k++){
				if(a[i]+a[j]+a[k]==s)return puts("YES"),0;
			}
		}
	}
	puts("NO");
}