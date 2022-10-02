#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{  
    string s;
    cin >> s;
    int n = s.size();
    int k = 0;
    for(int i =0; i<n; i++){
      if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
        k++;
      }
    }
    if(k > 0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    return 0;
}