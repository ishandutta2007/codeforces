#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int n,a[N],t;
int main(){
#ifdef flukehn
	freopen("F.txt","r",stdin);
#endif
	cin>>n;
	int i,j,x,y=-1;
	for(i=2;i*i<n;++i)
		if(n%i==0){
			a[++t]=n/i;
			a[++t]=i;
		}
	if(n%i==0)a[++t]=i;
	sort(a+1,a+t+1);
	if(t<2){
		puts("NO");
		return 0;
	}
	
	x=a[1];
	for(j=2;j<=t;++j)
		if(__gcd(x,a[j])==1){y=a[j];break;}
	if(y<0){
		puts("NO");
		return 0;
	}
	puts("YES");
	--n;
	for(i=0;i*x<=n;++i)
		if((n-i*x)%y==0)
			break;
	j=(n-i*x)/y;
	printf("%d\n%d %d\n%d %d\n",2,i,n/x+1,j,n/y+1);
}