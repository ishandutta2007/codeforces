#include<cstdio>
#include<cstring>
using namespace std;
char temp[105],len;
bool check()
{
	if(len%2==0) return false;
	for(int i=1;i<len;i++)
	{
		if(temp[i]!='0') return false;
	} 
	return true;
}
int main()
{
	scanf("%s",temp);
	len=strlen(temp);
	int ans=(len+1)/2;
	if(check()) ans--;
	printf("%d\n",ans);
	return 0;
}