#include<bits/stdc++.h>
using namespace std;
#define N 505
int main(){
	int n;
	scanf("%d",&n);
	int a=1234567;
	int b=123456;
	int c=1234;
	int ok=0;
	for(int i=0;a*i<=n;i++){
		for(int j=0;a*i+b*j<=n;j++)
		{
			if((n-a*i-b*j)%c==0)
			ok=1;
		}
	}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}