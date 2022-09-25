#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],c[N];
void Solve(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>c[i];
		a[i]=1;
	}
	for(int i=0;i<n;++i){
		if(!c[i])a[i]=0;
		if(!a[i])c[i]+=i;
		a[c[i]]=0;
		cout<<a[i]<<' ';
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