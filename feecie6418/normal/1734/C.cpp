#include<bits/stdc++.h>
using namespace std;
int n,f[1000005];
char a[1000005];
void Solve(){
	cin>>n>>a+1;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(a[j]=='1')break;
			f[j]=min(f[j],i);
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++)if(a[i]=='0')sum+=f[i];
	cout<<sum<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}