#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int ret = 0;
  while(N--) {
    string S;
    cin >> S;
    if(S == "Tetrahedron") ret += 4;
    else if(S == "Cube") ret += 6;
    else if(S == "Octahedron") ret += 8;
    else if(S == "Dodecahedron") ret += 12;
    else ret += 20;
  }
  cout << ret << endl;
}