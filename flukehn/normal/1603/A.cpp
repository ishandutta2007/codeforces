#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int a[N];
int n;
int work(){
	for(int i=1;i<=n;++i){
		int j;
		for(j=2;j<=i+1;++j)
			if(a[i]%j)break;
		if(j>i+1)return 0;
	}
	return 1;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		cout<<(work()?"YES":"NO")<<"\n";
	}
}