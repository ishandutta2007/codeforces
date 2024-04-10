#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ifstream in;
ofstream out;
int n, a[111], r1, c1, r2, c2;
int main()
{
	int min=222222, minl=111111;
	in.open("input.txt");
	out.open("output.txt");
	in >> n;
	for (int i=0; i<n; i++) in >> a[i];
	in >> r1 >> c1 >> r2 >> c2;
	if (r1<r2){
		minl=c1;
		for (int i=r1; i<=r2; i++) if (a[i-1]<minl) minl=a[i-1]+1;
		min=abs(minl-c2)+r2-r1;
		int ml2=minl;
		for (int i=r1-1; i>0; i--) {
			if (a[i-1]+1<minl) minl=a[i-1]+1;
			if (min>abs(minl-c2)+r2-r1+2*(r1-i)) min = abs(minl-c2)+r2-r1+2*(r1-i);
		}
		minl=ml2;
		for (int i=r2+1; i<=n; i++) {
			if (a[i-1]+1<minl) minl=a[i-1]+1;
			if (min>abs(minl-c2)+r2-r1+2*(i-r2)) min = abs(minl-c2)+r2-r1+2*(i-r2);
		}
	} else {
		minl=c1;
		for (int i=r1; i>=r2; i--) if (a[i-1]<minl) minl=a[i-1]+1;
		min=abs(minl-c2)+r1-r2;
		int ml2=minl;
		for (int i=r2-1; i>0; i--) {
			if (a[i-1]+1<minl) minl=a[i-1]+1;
			if (min>abs(minl-c2)+r1-r2+2*(r2-i)) min = abs(minl-c2)+r1-r2+2*(r2-i);
		}
		minl=ml2;
		for (int i=r1+1; i<=n; i++) {
			if (a[i-1]+1<minl) minl=a[i-1]+1;
			if (min>abs(minl-c2)+r1-r2+2*(i-r1)) min = abs(minl-c2)+r1-r2+2*(i-r1);
		}
	}
	out << min;
    return 0;
}