#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> br;
string str;

int main() {
    cin >> str;
    int co=0,flag=1;
    for(int i=0;i<str.size();i++) {
            if(str[i] == '(') co++;
            else if(str[i] == ')') co--;
            else {
                 br.push_back(1);
                 co--;
            }
            if(co<0 && flag == 1) {
                     puts("-1");
                     flag = 0;
            }
    }
    br[br.size()-1] += co;
    
    co = 0;
    int j=0;
    for(int i=0;i<str.size();i++) {
            if(str[i] == '(') co++;
            else if(str[i] == ')') co--;
            else {
                 co -= br[j];
                 j++;
            }
            if(co<0 && flag == 1) {
                     puts("-1");
                     flag = 0;
                     break;
            }
    }
    if(flag == 1) {
            for(int i=0;i<br.size();i++) printf("%d\n",br[i]);
    }
    return 0;
}
// (((#)((#)()((#((#(#()