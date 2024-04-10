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
int n;
bool is_lucky(int p)
{
	bool k=true;
	int t=p;
	while(t>0)
	{
		if(t%10!=4 && t%10!=7)k=false;
		t/=10;
	}
	if(k)return true;
	for(int i=2;i<p;i++)
		if(p%i==0 && is_lucky(i))
			return true;
	return false;
}
int main() {
	scanf("%d",&n);
	if(is_lucky(n))printf("YES\n");
	else printf("NO\n");
	return 0;
}