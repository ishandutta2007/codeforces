#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
#define N 300000030
int n;
uint A,B,C,D;
bitset<N/3> ntp;
uint f(int x){
	return A*x*x*x+B*x*x+C*x+D;	
}
uint calc(int p){
	uint tot=0;
	int t=1;
	while(true){
		if(1LL*p*t>n)break;
		t*=p;
		tot+=n/t;	
	}
	return tot*f(p);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>A>>B>>C>>D;
	uint ans=calc(2)+calc(3);
	for(int i=5;i<=n;++i){
		if(!(i&1)||i%3==0)continue;
		if(!ntp[i/3]){
			ans+=calc(i);
			for(int j=i*3;j<=n;j+=i<<1){
				if(j%3)ntp[j/3]=1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}