#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	int u,v,w;
	while(cin>>u>>v>>w){
		int a,b,c;
		for(a=1;a<=u;++a)if(u%a==0){
			b=u/a;
			if(v%a==0&&w%b==0&&(c=v/a)==w/b)break;
		}
		cout<<4*(a+b+c)<<"\n";
	}
}