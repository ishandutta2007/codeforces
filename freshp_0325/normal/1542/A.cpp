#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n,a=0,b=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
		{
			int x;
			scanf("%d",&x);
			if(x&1)	++a;
			else	++b;
		}
		puts(a==b?"Yes":"No");
	}
	return 0;
}