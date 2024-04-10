#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string a;
  cin >> n >> a;
  
  int sum = 0;
  set<int> s; 
  for (char c : a)
  {
    sum += c - '0';
    s.insert(sum);
  }
  
  if (!sum) cout << "YES" << endl;
  else
  {
    for (int i = 1; i * 2 <= sum; i++)
      if (sum % i == 0)
      {
        int isGood = 1;
        for (int j = i; j <= sum; j += i)
          isGood &= s.count(j);
        if (isGood)
        {
          cout << "YES" << endl;
          return 0;
        }
      }
    
    cout << "NO" << endl;
  }
}