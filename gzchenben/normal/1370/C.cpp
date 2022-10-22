#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,t;
bool pr(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true; 
}
int main() 
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1) printf("FastestFinger\n");
		if(n==2) printf("Ashishgup\n");
		if(n==3) printf("Ashishgup\n");
		if(n==4) printf("FastestFinger\n");
		if(n<=4) continue;
		if(n%2==0 && n%4!=0) 
		{
			if(pr(n/2)) printf("FastestFinger\n");
			else printf("Ashishgup\n");
			continue;
		}
		while(n%2==0) n/=2;
		if(n==1) printf("FastestFinger\n");
		else printf("Ashishgup\n");
	}
}