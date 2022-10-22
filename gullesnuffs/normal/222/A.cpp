#include <stdio.h>

using namespace std;

int main()
{
	int n, k, a[100005];
	scanf("%d%d", &n, &k);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int j=k-1; j < n-1; ++j){
		if(a[j] != a[j+1]){
			printf("-1");
			return 0;
		}
	}
	int i;
	for(i=k-2; i >= 0; --i){
		if(a[i] != a[i+1])
			break;
	}
	printf("%d\n", i+1);
	return 0;
}