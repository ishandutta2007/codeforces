#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  const char* names[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
  int n = sizeof(names)/sizeof(names[0]);
  map<string, int> kind;

  for (int i = 0; i < n; i++)
    kind[string(names[i])] = i;

  bool invalid = false;

  int v[3];
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    if (kind.find(s) == kind.end())
      invalid = true;
    v[i] = kind[s];
  }
  
  int ret;

  if (invalid) ret = -1;
  else {
    ret = -1;
    sort(v, v+3);
    do {
      if ((v[1] - v[0] + n)%n == 4 && (v[2] - v[1] + n)%n == 3) ret = 0;
      if ((v[1] - v[0] + n)%n == 3 && (v[2] - v[1] + n)%n == 4) ret = 1;
    } while(next_permutation(v, v+3));
  }

  if (ret == -1) printf("strange\n");
  else if (ret == 0) printf("major\n");
  else printf("minor\n");
  
  return 0;
}