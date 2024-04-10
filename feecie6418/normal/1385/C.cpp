#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n==1){
			puts("0");
			continue;
		}
		int p=n;
		while(a[p-1]>=a[p]&&p>1)p--;
		if(p==1){
			puts("0");
			continue;
		}
		while(a[p-1]<=a[p]&&p>1)p--;
		cout<<p-1<<endl;
	}
	return 0;
}