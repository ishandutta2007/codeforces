#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define ll long long
int T,i,j,n,a[N],x,y;
unsigned ll ans;
int main(){
	ios::sync_with_stdio(0); 
	cin>>T;
//	T=1;
	while(T--){
		cin>>n;
		ans=1;
		for(i=1;i<=n;++i){
			cin>>a[i];
			while(a[i]%2==0)a[i]>>=1,ans<<=1;
		}
		sort(a+1,a+n+1);
		ans=ans*a[n];
		for(i=1;i<n;++i)ans+=a[i];
		cout<<ans<<"\n";
	}
	return 0;
}