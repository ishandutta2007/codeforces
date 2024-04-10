#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>   
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <memory.h>
#include <cstring>
#include <map>
#include <time.h>
#include <string>
#include <iterator>
using namespace std;
//#pragma comment(linker, "/STACK:9999999999")

int n,w[200105],h[200105];
int ans,mx1=-2e9,mxi1,mx2=-2e9,mxi2;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&w[i],&h[i]);
		ans += w[i];
		if (h[i] > mx1) {
			mxi2 = mxi1;
			mx2 = mx1;
			mxi1 = i;
			mx1 = h[i];
		} else if (h[i] > mx2) {
			mxi2 = i;
			mx2 = h[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (mxi1 == i) {
			printf("%d ",(ans - w[i]) * mx2);
		} else {
			printf("%d ",(ans - w[i]) * mx1);
		}
	}
	return 0;
}