#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	char n[100]={0},m[100]={0};
	scanf("%s%s",n,m);
	bool sym=true;
	long kol[10]={0};
	for(int i=0;i<strlen(n);i++)
	{
		kol[n[i]-'0']++;
	}
	long long M=0;
	for(int i=1;i<=9;i++)
		if (kol[i]>0)
		{
			M=i;
			kol[i]--;
			break;
		}
	for(int i=0;i<=9;i++)
		if (kol[i]>0)
		{
			M=M*10+i;
			kol[i]--;
			i--;
		}
	if (M!=atol(m)) sym=false;
	if (strlen(n)!=strlen(m)) sym=false;
	printf("%s\n",((sym) ? "OK" : "WRONG_ANSWER"));
	return 0;
}