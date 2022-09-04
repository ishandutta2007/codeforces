#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main(){
	long long int n,x,ans=0;
	scanf("%I64d %I64d\n",&n,&x);
	for(int i=0;i<n;i++){
		char a;
		long long int b;
		scanf("%c %I64d",&a,&b);
		getchar();
		if(a=='+')
		x+=b;
		else if(x<b)
		ans++;
		else
		x-=b;
	}
	printf("%I64d %I64d\n",x,ans);
}