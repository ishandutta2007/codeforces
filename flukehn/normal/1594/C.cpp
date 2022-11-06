#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
int n;
char c,s[N];
int p[N];
void work(){
	int tot=0;
	for(int i=1;i<=n;++i){
		tot+=(s[i]!=c);
	}
	if(!tot) {
		cout<<0<<"\n";
	}
	else if(s[n]==c || s[n-1] == c) {
		cout<<1<<"\n";
		if(s[n]==c)cout<<n<<"\n";
		else cout<<n-1<<"\n";
	}else{
		for(int i=1;i<=n;++i)p[i]=(s[i]!=c);
		for(int i=n;i>=1;--i)
			for(int j=i+i;j<=n;j+=i)p[i]|=p[j];
		int i;
		for(i=1;i<=n;++i)if(!p[i])break;
		if(i<=n){
			cout<<1<<"\n"<<i<<"\n";
		}
		else cout<<2<<"\n"<<n-1<<" "<<n<<"\n";
	}
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>c>>s+1){
		work();
	}
}