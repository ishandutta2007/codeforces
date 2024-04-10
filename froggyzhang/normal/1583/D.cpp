#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
int n,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a[n]=n;
	for(int i=1,x;i<n;++i){
		cout<<'?';
		for(int j=1;j<n;++j){
			cout<<' '<<n;
		}
		cout<<' '<<n-i<<endl;
		cin>>x;
		if(!x){
			a[n]=i;
			break;
		}
	}
	for(int i=1,x;i<=n;++i){
		if(i==a[n])continue;
		cout<<'?';
		for(int j=1;j<n;++j){
			cout<<' '<<a[n];
		}
		cout<<' '<<i<<endl;
		cin>>x;
		a[x]=i;
	}
	cout<<'!';
	for(int i=1;i<=n;++i){
		cout<<' '<<a[i];
	}
	cout<<endl;
	return 0;
}