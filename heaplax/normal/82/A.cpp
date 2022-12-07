#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
long long n,add=1,c;
string s[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
int main()
{
	scanf("%I64d",&n);
	while(n>5*add)
	{
		n-=5*add;
		add*=2;
	}
	c=n%add;
	n=n/add-1;
	if(c>0)n++;
	cout<<s[n]<<endl;///
	return 0;
}