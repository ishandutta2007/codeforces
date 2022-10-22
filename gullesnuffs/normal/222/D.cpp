#include <stdio.h>
#include <algorithm>

using namespace std;

int score[2][100005];

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	for(int j=0; j < 2; ++j)
		for(int i=0; i < n; ++i)
			scanf("%d", score[j]+i);
	for(int j=0; j < 2; ++j)
		sort(score[j], score[j]+n);
	int pos=0, best=1, worst=0;
	for(int j=n-1; j >= 0; --j){
		while(score[0][pos]+score[1][j] < x){
			++pos;
			if(pos >= n)
				break;
		}
		if(pos >= n)
			break;
		++pos;
		++worst;
	}
	printf("1 %d", worst);
	return 0;
}