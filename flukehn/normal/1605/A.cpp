#include<bits/stdc++.h>
using namespace std;

long long work(){
	long long a,b,c;
	cin>>a>>b>>c;
	return (a+c-2*b)%3==0?0:1;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cout<<work()<<"\n";
	}
}