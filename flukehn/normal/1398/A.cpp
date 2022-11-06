#include<bits/stdc++.h>
using namespace std;
const int N=50011;
int a[N],n;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(a[n]>=a[1]+a[2]){
			cout<<"1 2 "<<n<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
}