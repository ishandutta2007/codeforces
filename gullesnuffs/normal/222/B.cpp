#include <stdio.h>

using namespace std;

int colN, rowN, queryN, number[1005][1005];
int col[1005], row[1005];

int main()
{
	scanf("%d%d%d", &colN, &rowN, &queryN);
	for(int i=0; i < colN; ++i)
		for(int j=0; j < rowN; ++j)
			scanf("%d", number[i]+j);
	for(int i=0; i < colN; ++i)
		row[i]=i;
	for(int i=0; i < rowN; ++i)
		col[i]=i;
	for(int i=0; i < queryN; ++i){
		char type[2];
		int a, b;
		scanf("%s", type);
		scanf("%d%d", &a, &b);
		--a;
		--b;
		if(type[0] == 'c'){
			int t=col[a];
			col[a]=col[b];
			col[b]=t;
		}
		else if(type[0] == 'r'){
			int t=row[a];
			row[a]=row[b];
			row[b]=t;
		}
		else{
			printf("%d\n", number[row[a]][col[b]]);
		}
	}
	return 0;
}