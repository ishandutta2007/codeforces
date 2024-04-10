#include <cstdio>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	char D[4][4]={0};
	scanf("%s%s%s",D[0],D[1],D[2]);
	bool sym=true;
	if (D[0][0]!=D[2][2]) sym=false;
	if (D[0][1]!=D[2][1]) sym=false;
	if (D[1][0]!=D[1][2]) sym=false;
	if (D[2][0]!=D[0][2]) sym=false;
	printf("%s\n",((sym) ? "YES" : "NO"));
	return 0;
}