#include <stdio.h>

using namespace std;
long long n;
double mult[2][128];
char input[2][200005];

int main()
{
	scanf("%I64d", &n);
	scanf("%s%s",  input[0], input[1]);
	double ans=0, total=0;
	for(int i=0; i < n; ++i){
		ans += mult[1][input[0][i]]*(n-i);
		mult[0][input[0][i]] += i+1;
		ans += mult[0][input[1][i]]*(n-i);
		mult[1][input[1][i]] += i+1;
	}
	total=(n*(n+1)*(2*n+1))/6;
	printf("%.8lf", ans/total);
	return 0;
}