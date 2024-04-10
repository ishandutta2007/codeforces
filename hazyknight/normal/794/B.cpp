#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef double db;

int n,h;

int main()
{
	scanf("%d%d",&n,&h);
	db area = (db)h / n;
	for (int i = 1;i < n;i++)
	{
		db cur = sqrt(area * i / h);
		printf("%.10lf ",cur * h);
	}
	printf("\n");
	return 0;
}