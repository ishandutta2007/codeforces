#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
int n,a[N];
bool isprime(int x){	
	if(x==1)return false;
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;	
}
void Solve(){
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];	
	}
	if(!isprime(sum)){
		cout<<n<<'\n';
		for(int i=1;i<=n;++i){
			cout<<i<<' ';
		}
		cout<<'\n';
		return;	
	}
	if(n==3&&a[1]==a[2]&&a[1]==a[3]&&a[1]==1){
		cout<<1<<'\n'<<1<<'\n';
		return;	
	}
	int pos=0;
	for(int i=1;i<=n;++i){
		if(!isprime(sum-a[i])){
			pos=i;break;
		}	
	}
	cout<<n-1<<'\n';
	for(int i=1;i<=n;++i){
		if(i==pos)continue;
		cout<<i<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}