#include <bits/stdc++.h>
using namespace std;

string s[6] = {
  "+------------------------+",
  "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
  "|#.#.#.#.#.#.#.#.#.#.#.|.|",
  "|#.......................|",
  "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
  "+------------------------+"
};

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  
  for (int j = 0; j < 11; j++)
    for (int i = 1; i < 5; i++)
      if (s[i][j * 2 + 1] == '#' && n)
      {
        s[i][j * 2 + 1] = 'O';
        n--;
      }
      
  for (int i = 0; i < 6; i++)
    cout << s[i] << endl;
}