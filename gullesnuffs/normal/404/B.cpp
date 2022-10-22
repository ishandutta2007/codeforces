#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	double a, d;
	scanf("%lf%lf", &a, &d);
	int n;
	scanf("%d", &n);
	double p=4*a;
	for(int i=1; i <= n; ++i){
		double len=d*i;
		len-=p*floor(len/p);
		double x, y;
		while(len >= p)
			len -= p;
		double b=len;
		while(b >= a)
			b -= a;
		if(len < a)
			x=len, y=0;
		else if(len < 2*a)
			x=a, y=b;
		else if(len < 3*a)
			x=a-b, y=a;
		else
			x=0, y=a-b;
		printf("%lf %lf\n", x, y);
	}
	return 0;
}