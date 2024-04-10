#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
void Solve(){
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x;
	cout<<n/2*6<<'\n';
	for(int i=1;i<=n;i+=2){
		printf("%d %d %d\n",1,i,i+1);
		printf("%d %d %d\n",2,i,i+1);
		printf("%d %d %d\n",1,i,i+1);
		printf("%d %d %d\n",2,i,i+1);
		printf("%d %d %d\n",1,i,i+1);
		printf("%d %d %d\n",2,i,i+1);
	}
}
int main(){
	cin>>t;
	while(t--)Solve();
}