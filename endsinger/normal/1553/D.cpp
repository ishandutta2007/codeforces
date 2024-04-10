#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
char s[N],t[N];
void sol()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int px=1,py=1;
	if(n%2!=m%2)
		px++;
	while(1)
	{
		if(s[px]!=t[py])
			px+=2;
		else
		{
			px++;
			py++;
		}
		if(py>m)
			break;
		if(px>n)
			break;
	}
	if(py>m)
		puts("YES");
	else
		puts("NO");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}