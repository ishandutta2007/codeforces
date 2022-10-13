#include <bits/stdc++.h>
using namespace std;
const string KEYBOARD[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

int main()
{
  ios::sync_with_stdio(0);
  string direction, message;
  cin >> direction >> message;
  for (int i = 0; i < int(message.size()); i++)
    for (int row = 0; row < 3; row++)
      for (int col = 0; col < 10; col++)
        if (KEYBOARD[row][col] == message[i])
          cout << (direction == "L" ? KEYBOARD[row][col + 1] : KEYBOARD[row][col - 1]);
}