// Codeforces Beta Round #2
// Problem A -- Winner
#include <iostream>
#include <string>
#include <map>

#define maxN 1000

using namespace std;

int n, score[maxN];
string name[maxN];
map<string, int> now, fin;

int main()
{
  cin >> n;
  fin.clear();
  for(int i = 0; i < n; ++ i)
  {
    cin >> name[i] >> score[i];
    fin[name[i]] += score[i];
  }
  int m = 0;
  for(map<string, int>::iterator iter = fin.begin(); iter != fin.end(); ++ iter)
    if(iter->second > m)
      m = iter->second;
  now.clear();
  for(int i = 0; i < n; ++ i)
  {
    now[name[i]] += score[i];
    if(now[name[i]] >= m && fin[name[i]] == m)
    {
      cout << name[i] << "\n";
      break;
    }
  }
  return 0;
}