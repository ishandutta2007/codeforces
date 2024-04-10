#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<4;++i){
		cin>>a[i];
	}	
	sort(a,a+4);
	cout<<a[3]-a[0]<<' '<<a[3]-a[1]<<' '<<a[3]-a[2]<<'\n';
	return 0;
}