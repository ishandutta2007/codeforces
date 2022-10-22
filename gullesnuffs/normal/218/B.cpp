#include <stdio.h>
#include <algorithm>

using namespace std;

int personN, airplaneN;
int a[1100], b[1100];

int main()
{
	scanf("%d%d", &personN, &airplaneN);
	for(int i=0; i < airplaneN; ++i)
		scanf("%d", a+i);
	sort(a, a+airplaneN);
	for(int i=0; i < airplaneN; ++i)
		b[i]=a[i];
	//Max
	int ans=0;
	for(int i=0; i < personN; ++i){
		int Min=-1;
		for(int j=0; j < airplaneN; ++j){
			if(b[j] && (Min < 0 || b[j] > b[Min]))
				Min=j;
		}
		if(Min < 0)
			continue;
		ans += b[Min];
		--b[Min];
	}
	printf("%d", ans);
	for(int i=0; i < airplaneN; ++i)
		b[i]=a[i];
	//Min
	ans=0;
	for(int i=0; i < personN; ++i){
		int Min=-1;
		for(int j=0; j < airplaneN; ++j){
			if(b[j] && (Min < 0 || b[j] < b[Min]))
				Min=j;
		}
		if(Min < 0)
			continue;
		ans += b[Min];
		--b[Min];
	}
	printf(" %d", ans);
	return 0;
}