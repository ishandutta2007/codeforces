#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main(){
  string s;
  cin >> s;
  for(int i = 0; i <= s.size(); i++){ //
    for(int j = 0; j < 26; j++){
      string str = s.substr(0, i) + (char)('a' + j) + s.substr(i);

      bool judge = true;
      for(int i = 0, j = str.size() - 1; i < j; i++, j--){
        if(str[i] != str[j]) judge = false;
      }
      if(judge){
        cout << str << endl;
        exit(0);
      }
    }
  }
  cout << "NA" << endl;
}