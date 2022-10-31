#include <iostream>
#include <fstream>

using namespace std;
ifstream in;
ofstream out;
int n, a[5555], b, l=1, r=1, sum=0, m=-1;
int main()
{
	in.open("input.txt");
	out.open("output.txt");
	in >> n;
	for (int i=0; i<n; i++) {
		in >> b;
		a[b]++;
	}
	for (int i=1; i<=5000; i++) {
		while (l<i) sum-=a[l], l++;
		while (r<=i*2 && r<=5000) sum+=a[r], r++;
		if (sum > m) m=sum;
	}
	out << n-m;
    return 0;
}