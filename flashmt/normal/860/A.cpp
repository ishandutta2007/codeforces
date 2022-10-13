#include <bits/stdc++.h>
using namespace std;
const string VOWELS = "aeiou";

int main()
{
  string s, word = "";
  set <char> consonantSet;
  int consonant = 0;
  cin >> s;
  vector <string> ans;
  for (char c : s)
    if (VOWELS.find(c) != string::npos)
    {
      word += c;
      consonant = 0;
      consonantSet.clear();
    }
    else
    {
      if (consonant >= 2 && (c != *consonantSet.begin() || consonantSet.size() > 1))
      {
        cout << word << ' ';
        word = "";
        consonant = 0;
        consonantSet.clear();
      }
      word += c;
      consonant++;
      consonantSet.insert(c);
    }
  if (!word.empty())
    cout << word << endl;
}