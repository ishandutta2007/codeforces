#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
int n,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0,j=0;j<=60;++i){
		for(int k=0;k<=i;++k)a[j++]=i;
	}
	cin>>n;
	int x=0,z;
	while(n--)cin>>z,x^=a[z];
	cout<<(x?"NO\n":"YES\n");
	return 0;
}