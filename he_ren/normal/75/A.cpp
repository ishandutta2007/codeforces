#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int change(int x)
{
	static char s[15];
	sprintf(s+1,"%d",x);
	int res = 0;
	for(int i=1; s[i]; ++i)
		if(s[i] != '0') res = res * 10 + s[i] - '0';
	return res;
}

int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(change(a) + change(b) == change(a+b)) printf("YES");
	else printf("NO");
	return 0;
}