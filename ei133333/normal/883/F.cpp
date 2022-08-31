#include<bits/stdc++.h>

using namespace std;


string norm(string a)
{
  string k;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == 'u') {
      k += "oo";
    } else if(i + 1 < a.size() && a[i] == 'k' && a[i + 1] == 'h') {
      k += "h";
      i++;
    } else {
      k += a[i];
    }
  }
  return (k);
}

int main()
{
  int N;
  set< string > s;

  cin >> N;
  for(int i = 0; i < N; i++) {
    string S;
    cin >> S;
    while(norm(S) != S) S = norm(S);
    s.emplace(S);
  }
  cout << s.size() << endl;
}