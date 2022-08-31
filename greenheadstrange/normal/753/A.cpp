#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int t[100], top = 1;
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	while(sum + top <= n)
	{
		t[top] = top;
		sum += top;
		top++;
	}
	t[top - 1] += n - sum;
	printf("%d\n", top - 1);
	for(int i = 1; i < top; i++)
		printf("%d ",t[i]);
}