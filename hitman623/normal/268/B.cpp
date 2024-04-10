#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
  double n;
  cin>>n;
  cout<< fixed << setprecision(0)<<(n*(n*n+5))/6;
  return 0;
}