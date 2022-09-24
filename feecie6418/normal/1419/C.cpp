#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,a[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int s=0,p=0;
		cin>>n>>x;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==x)p=1;
			s+=a[i];
		}
		if(x*n==s){
			sort(a+1,a+n+1);
			if(a[1]==a[n])puts("0");
			else puts("1");
		}
		else if(!p)puts("2");
		else puts("1");
	}
}