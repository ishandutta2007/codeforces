#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	while(cin>>a>>b>>c){
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a>b)swap(a,b);
		cout<<max(0LL,c-a-b+1)<<"\n";
	}
}