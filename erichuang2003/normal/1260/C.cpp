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

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

int T,a,b,k;

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	read(T);
	while (T--)
	{
		read(a),read(b),read(k);
		if (a > b)
			swap(a,b);
		int g = gcd(a,b);
		puts((b - g - 1) / a + 1 < k ? "OBEY" : "REBEL");
	}
	return 0;
}