#include <stdio.h>

using namespace std;

int main()
{
	long long l, r, ans=0, i;
	scanf("%I64d%I64d", &l, &r);
	if(l <= 9){
		ans += 10-l;
	}
	else{
	for(i=l; i>=10; i/=10);
	if(i >= l%10)
		++ans;
	}
	if(r <= 9){
		ans -= 9-r;
	}
	else{
	for(i=r; i>=10; i/=10);
	if(i <= r%10)
		++ans;
	}
	if(r >= 10)
		ans += r/10-l/10-1;
	printf("%I64d", ans);
	return 0;
}