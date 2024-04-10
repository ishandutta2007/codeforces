#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int num[N],id[N];
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
bool _2[N];
int main()
{
    srand(23333);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]),id[i]=i;
	for(int _=0;_<100;_++)
	{
		random_shuffle(id+1,id+n+1);
		int g1=num[id[1]],g2=0;_2[id[1]]=false;
		for(int i=2;i<=n;i++)
		if(num[id[i]]%g1==0) g2=gcd(num[id[i]],g2),_2[id[i]]=true;
		else g1=gcd(g1,num[id[i]]),_2[id[i]]=false;
		if(g1==1 && g2==1){puts("YES");for(int i=1;i<=n;i++) printf("%d ",1+(int)_2[i]);return 0;}
	}
	puts("NO");
	return 0;
}