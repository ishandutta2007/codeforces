// Codeforces Beta Round #5
// Problem B -- Center Alignment
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> text;

void repeat(char c, int s)
{
  for(int i = 0; i < s; ++ i)
    cout << c;
}

int main()
{
  text.clear();
  string temp;  
  while(getline(cin, temp))
    text.push_back(temp);
  int width = 0;
  for(vector<string>::iterator iter = text.begin(); iter != text.end(); ++ iter)
    width = max(width, (int)iter->size());
  repeat('*', width + 2);
  cout << "\n";
  int times = 0;
  for(vector<string>::iterator iter = text.begin(); iter != text.end(); ++ iter)
  {
    repeat('*', 1);
    int L, R;
    if((width - iter->size()) & 1)
    {
      if((++ times) & 1)
        L = (int)floor((width - iter->size()) / 2.0), R = (int)ceil((width - iter->size()) / 2.0);
      else
        L = (int)ceil((width - iter->size()) / 2.0), R = (int)floor((width - iter->size()) / 2.0);
    }
    else
      L = R = (width - iter->size()) >> 1;
    repeat(' ', L);
    cout << *iter;    
    repeat(' ', R), repeat('*', 1);
    cout << "\n";
  }
  repeat('*', width + 2);
  cout << "\n";
  return 0;
}