#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

long double calc(int type, long double x, long double y, long double z) {
  return type == 0 ? pow(y, z) * log10(x)
                   : z * log10(pow(x, y));
}

char out[12][12] = {"x^y^z",
                    "x^z^y",
                    "(x^y)^z",
                    "(x^z)^y",
                    "y^x^z",
                    "y^z^x",
                    "(y^x)^z",
                    "(y^z)^x",
                    "z^x^y",
                    "z^y^x",
                    "(z^x)^y",
                    "(z^y)^x"};

int main() {
  double x, y, z;
  cin >> x >> y >> z;
  double what[12][3] = {{x, y, z},
                        {x, z, y},

                        {x, y, z},
                        {x, z, y},
                        
                        {y, x, z},
                        {y, z, x},
                        
                        {y, x, z},
                        {y, z, x},
                        
                        {z, x, y},
                        {z, y, x},
                        
                        {z, x, y},
                        {z, y, x}};

  int ind = 0;
  for (int i = 0; i < 12; ++i) {
    if (calc((i / 2) & 1, what[i][0], what[i][1], what[i][2]) > calc((ind / 2) & 1, what[ind][0], what[ind][1], what[ind][2]) + 1e-14) {
      ind = i;
    }
  }

  cout << out[ind] << endl;

  return 0;
}