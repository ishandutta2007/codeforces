#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[100005], b[100005], wrongN;

int main()
{
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		b[i]=a[i];
	}
	sort(b, b+n);
	wrongN=0;
	for(int i=0; i < n; ++i)
		if(a[i] != b[i])
			++wrongN;
	if(wrongN > 2){
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}