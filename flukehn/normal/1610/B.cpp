#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n;
int a[N];
int chk(int x){
	int l,r;
	for(l=1,r=n;l<r;++l,--r){
		while(l<=n&&a[l]==x)++l;
		while(r>=1&&a[r]==x)--r;
		if(l<r&&a[l]!=a[r])return 0;
	}
	return 1;
}
int work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l,r;
	for(l=1,r=n;l<r;++l,--r)
		if(a[l]!=a[r])break;
	if(l>=r)return 1;
	return chk(a[l])||chk(a[r]);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)cout<<(work()?"YES":"NO")<<"\n";
}