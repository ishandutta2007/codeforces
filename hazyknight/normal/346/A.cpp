#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

int n;
 
int main()
{
	scanf("%d",&n);
	int g = 0,MX = 0;
	for (int i = 1;i <= n;i++)
	{
		int a;
		scanf("%d",&a);
		g = __gcd(a,g);
		MX = max(MX,a);
	}
	puts((MX / g - n) & 1 ? "Alice" : "Bob");
	return 0;
}