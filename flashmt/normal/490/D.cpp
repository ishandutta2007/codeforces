#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

map <int,int> stepA, stepB, stepC, stepD;
map <long long,int> stepAB, traceAB;

void att(int x, int curStep, map <int,int> &step)
{
  if (step.count(x)) return;
  step[x] = curStep;
  if (x % 2 == 0) att(x / 2, curStep + 1, step);
  if (x % 3 == 0) att(x - x / 3, curStep + 1, step);
}

int main()
{
  ios::sync_with_stdio(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  att(a, 0, stepA);
  att(b, 0, stepB);
  att(c, 0, stepC);
  att(d, 0, stepD);
  
  for (map <int,int>::iterator it = stepA.begin(); it != stepA.end(); it++)
    for (map <int,int>::iterator itt = stepB.begin(); itt != stepB.end(); itt++)
    {
      long long product = 1LL * it -> first * itt -> first;
      int totalStep = it -> second + itt -> second;
      if (!stepAB.count(product) || stepAB[product] > totalStep)
      {
        stepAB[product] = totalStep;
        traceAB[product] = it -> first;
      }
    }
    
  int ans = oo, ansA, ansB, ansC, ansD;
  for (map <int,int>::iterator it = stepC.begin(); it != stepC.end(); it++)
    for (map <int,int>::iterator itt = stepD.begin(); itt != stepD.end(); itt++)
    {
      long long product = 1LL * it -> first * itt -> first;
      int totalStep = it -> second + itt -> second;
      if (!stepAB.count(product)) continue;
      if (ans > totalStep + stepAB[product])
      {
        ans = totalStep + stepAB[product];
        ansA = traceAB[product];
        ansB = product / ansA;
        ansC = it -> first;
        ansD = itt -> first;
      }
    }
    
  if (ans == oo) cout << -1 << endl;
  else cout << ans << endl << ansA << ' ' << ansB << endl << ansC << ' ' << ansD << endl;
}