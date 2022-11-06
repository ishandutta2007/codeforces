#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
typedef long long L;
int a[2],n,b[N],c[N];
int main(){
#ifdef flukehn
	//freopen("g.in","r",stdin);
#endif
	L x,an=0;
	int i,t,y=0,j;
	cin>>n;
	a[0]=1;
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		t=0;
		for(;x;x>>=1)t+=x&1;
		y^=t&1;
		c[i]=c[i-1]+t;
		//cerr<<b[i]<<" "<<a[y]<<endl;
		
		an+=a[y];
		for(j=i;j&&i-j<=66;--j){
			t=max(t,c[j]-c[j-1]);
			if((c[i]-c[j-1])%2==0&&t*2>c[i]-c[j-1])
				--an;
			
		}
		//++a[b[i-1]];
		++a[y];
	}
	cout<<an<<endl;
}