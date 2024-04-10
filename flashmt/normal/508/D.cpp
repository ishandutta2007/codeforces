#include <bits/stdc++.h>
using namespace std;
const int C = 62;

int n, degIn[4000], degOut[4000];
vector <int> a[4000];
deque <int> ans;

int get(char c)
{
  if (c <= '9') return c - '0';
  if (c <= 'Z') return c - 'A' + 10;
  return c - 'a' + 36;
}

char conv(int c)
{
  if (c < 10) return char('0' + c);
  if (c < 36) return char('A' + c - 10);
  return char('a' + c - 36); 
}

void quit()
{
  cout << "NO\n";
  exit(0);
}

void visit(int x)
{
  while (!a[x].empty())
  {
    int y = a[x].back();
    a[x].pop_back();
    visit(y);
  }
  ans.push_front(x);
}

int main()
{
  ios::sync_with_stdio(0);
  string ss;
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> ss;
    int x = get(ss[0]) * C + get(ss[1]);
    int y = get(ss[1]) * C + get(ss[2]);
    a[x].push_back(y);
    degOut[x]++;
    degIn[y]++;
  }
  
  int s = -1, t = -1;
  for (int i = 0; i < C * C; i++)
    if (degIn[i] != degOut[i])
    {
      if (degIn[i] == degOut[i] + 1)
      {
        if (t >= 0) quit();
        t = i;
      }
      else if (degIn[i] + 1 == degOut[i])
      {
        if (s >= 0) quit();
        s = i;
      }
      else quit();
    }
  
  if (s < 0 && t < 0)
    for (int i = 0; i < C * C; i++)
      if (degOut[i])
        s = i;
   
  visit(s);
  if (ans.size() != n + 1) quit();
  
  cout << "YES\n";
  cout << conv(ans.front() / C);
  while (!ans.empty())
  {
    int x = ans.front();
    ans.pop_front();
    cout << conv(x % C);
  }
  cout << endl;
}