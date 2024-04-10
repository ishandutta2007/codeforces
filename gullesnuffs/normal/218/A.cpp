
#include <stdio.h>

using namespace std;

int peakN, changedN;
int r[1000];

int main()
{
	scanf("%d%d", &peakN, &changedN);
	for(int i=1; i <= 2*peakN+1; ++i){
		scanf("%d", r+i);
	}
	printf("%d", r[1]);
	for(int i=2; i <= 2*peakN+1; ++i){
		if(i%2){
			printf(" %d", r[i]);
			continue;
		}
		if(r[i] > r[i-1]+1 && r[i] > r[i+1]+1 && changedN){
			--changedN;
			printf(" %d", r[i]-1);
		}
		else{
			printf(" %d", r[i]);
		}
	}
	return 0;
}