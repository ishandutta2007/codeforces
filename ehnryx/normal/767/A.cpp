#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char snacksObtained[100001];

int main()
{
	memset(snacksObtained, 0, sizeof(snacksObtained));
	int N;
	scanf("%d", &N);

	int v;
	int pos = N;
	for(int i=0;i<N;++i)
	{
		scanf("%d", &v);
		snacksObtained[v] = 1;
		for(pos=pos;pos>0 && snacksObtained[pos] == 1;--pos)
		{
			printf("%d ", pos);
		}
		printf("\n");
	}

	return 0;
}