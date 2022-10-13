#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int a[6];
  for (int i = 0; i < 6; i++) cin >> a[i];
  sort(a, a + 6);
  for (int head = 0; head < 6; head++)
    for (int tail = head + 1; tail < 6; tail++)
    {
      set <int> legs;
      for (int i = 0; i < 6; i++)
        if (i != head && i != tail)
          legs.insert(a[i]);
          
      if (legs.size() > 1) continue;
      
      cout << (a[head] == a[tail] ? "Elephant" : "Bear") << endl;
      return 0;
    }
    
  cout << "Alien" << endl;
}