#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const double PI = acos(-1);
const double EPS = 1e-8;
int main()
{
  double D; 
  double H; // H *  * D^2 / 4 ml
  double V; // - V ml / s
  double E; // + E *  * D^2 / 4 ml / s
  
  cin >> D >> H >> V >> E;

  double Dec = V - E * PI * D * D / 4;
  
  if(Dec <= EPS) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << fixed << setprecision(10) << H * PI * D * D / 4 / Dec << endl;
  }
}