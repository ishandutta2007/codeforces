#include <iostream>
#include <cmath>

using namespace std;

long long n,m,i,j,k,l,x,y,z;

int main()
{
 cin >> n >> m;
 if (m==1) cout << n; else
 {while (n>0) {n/=2;k*=2;k++;}
 cout << k;}
 return 0;
}