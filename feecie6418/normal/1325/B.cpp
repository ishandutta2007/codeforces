#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		cout<<unique(a+1,a+n+1)-a-1<<endl;
	}
}