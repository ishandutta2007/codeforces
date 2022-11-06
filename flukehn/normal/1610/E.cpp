#include<bits/stdc++.h>
using namespace std;
//const int mo=1e9+7;
const int N=2e5+11;
int a[N];
int n;

int work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=2;
	for(int i=1;i<=n;++i){
		
		int j=upper_bound(a+i+1,a+n+1,a[i])-a;
		int tmp=j-i+(j<=n);
		while(j<=n){
			int p=lower_bound(a+j+1,a+n+1,2*a[j]-a[i])-a;
			if(p>n)break;
			++tmp;
			j=p;
		}
		ans=max(ans,tmp);
	}
	return n-ans;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)cout<<work()<<"\n";
}