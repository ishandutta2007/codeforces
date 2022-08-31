#include<bits/stdc++.h>
using namespace std;
bool check(string T)
{
  string A = "AHIMOTUVWXYovwx";
  if(T.size() % 2 == 1 && A.find(T[T.size() / 2]) == string::npos) return(false);
  for(int i = 0; i < T.size() / 2; i++) {
    int a = i, b = T.size() - i - 1;
    bool flag = false;
    if(A.find(T[a]) != string::npos && T[a] == T[b]) flag = true;
    if(T[a] == 'b' && T[b] == 'd') flag = true;
    if(T[a] == 'd' && T[b] == 'b') flag = true;
    if(T[a] == 'p' && T[b] == 'q') flag = true;
    if(T[a] == 'q' && T[b] == 'p') flag = true;
    if(!flag) return(false);
  }
  return(true);
}

   
int main()
{
  

  string T;
  cin >> T;
  if(!check(T)) {
    cout << "NIE" << endl;
  } else {
    cout << "TAK" << endl;
  }
}