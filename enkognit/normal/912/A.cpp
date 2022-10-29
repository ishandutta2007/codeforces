#include <iostream>
#include <cmath>

using namespace std;

long long n,m,i,j,k,l,x,y,z;

int main()
{
 cin >> n >> m;
 cin >> x >> y >> z;
 n-=x*2+y;
 if (n>0) n=0;
 m-=y+z*3;
 if (m>0) m=0;
 cout << -(n+m);
 return 0;
}