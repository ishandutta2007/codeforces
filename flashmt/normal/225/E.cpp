#include <iostream>
using namespace std;
const int a[] = {1,2,4,6,12,16,18,30,60,88,106,126,520,606,1278,
 2202,2280,3216,4252,4422,9688,9940,11212,19936,
 21700,23208,44496,86242,110502,132048,216090,
 756838,859432,1257786,1398268,2976220,3021376,
 6972592,13466916,20996010};
const int z = 1000000007;
 
long long p(int x)
{
	if (!x) return 1;
	long long res=p(x/2);
	res=res*res%z;
	return x%2?res*2%z:res;
}

int main()
{
 int n;
 cin >> n;
 cout << (p(a[n-1])+z-1)%z << endl;
}