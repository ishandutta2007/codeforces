#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int x,int y){
	return x%y?gcd(y,x%y):y;
}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		int g=gcd(a,b);
		a/=g,b/=g;
		if(a>b)swap(a,b);
		long long tmp=1+1ll*(k-1)*a;
		if(tmp>=b)puts("OBEY");
		else puts("REBEL");
	}
}