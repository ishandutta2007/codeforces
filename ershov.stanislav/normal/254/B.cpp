#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream in;
ofstream out;
int n, a[500];
int ml[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	in.open("input.txt");
	out.open("output.txt");
	in >> n;
	for (int i=0; i<n; i++) {
		int m, d, p, t;
		in >> m >> d >> p >> t;
		int day=0;
		for (int j=0; j<m-1; j++) day+=ml[j];
		day+=d;
		for (int j=day-1; j>day-1-t; j--) a[j+120]+=p;
	}
	int m=-1;
	for (int i=0; i<500; i++) m=max(a[i], m);
	out << m;
    return 0;
}