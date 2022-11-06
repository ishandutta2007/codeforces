#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n;
int a[N];
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		if(n>2){
			int p=2;
			for(int i=2;i<=n;++i)
				if(a[i]-a[i-1]<a[p]-a[p-1])p=i;
			reverse(a+1,a+p);
			reverse(a+p,a+n+1);
			reverse(a+1,a+n+1);
		}
		for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
	}
}