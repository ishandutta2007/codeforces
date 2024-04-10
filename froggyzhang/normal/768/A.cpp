#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	int mn=*min_element(a+1,a+n+1);
	int mx=*max_element(a+1,a+n+1);
	cout<<accumulate(a+1,a+n+1,0,[&](int i,int j){return i+(j!=mn&&j!=mx);});
	return 0;
}