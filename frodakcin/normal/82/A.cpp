#include <cstdio>
#include <iostream>
using namespace std;

int N;
string ans[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main(void)
{
	scanf("%d", &N);
	--N;
	for(int i=1;;i*=2)
	{
		if(N>=i*5)
			N -= i*5;
		else
		{
			cout << ans[N/i] << "\n";
			return 0;
		}
	}
}