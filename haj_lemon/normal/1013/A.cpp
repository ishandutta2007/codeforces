#include<bits/stdc++.h>
using namespace std;
int n,x,a,b;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){cin>>x;a+=x;}
	for (int i=1;i<=n;i++){cin>>x;b+=x;}
	if (a>=b) cout<<"Yes"<<endl;else cout<<"No"<<endl;
	return 0;
}