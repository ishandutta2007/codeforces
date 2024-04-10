#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <ctype.h>

using namespace std;

inline char op(char ori) {
    if(islower(ori))
        return ori - 32;
    return ori + 32;
}

string str1,str2;
map <char,int> a,b;
map <char,int>::iterator ait,bit;
int yay,boo;

int main() {
    cin >> str1 >> str2;

    for(int i=0;i<str1.size();i++) {
        a[str1[i]]++;
    }
    for(int i=0;i<str2.size();i++) {
        b[str2[i]]++;
    }

    for(ait = a.begin();ait != a.end(); ait++) {
        if(ait->second >= b[ait->first]) {
            yay += b[ait->first];
            a[ait->first] -= b[ait->first];
            b[ait->first] = 0;
        }
        else {
            yay += a[ait->first];
            b[ait->first] -= a[ait->first];
            a[ait->first] = 0;
        }
    }

    for(ait = a.begin();ait != a.end(); ait++) {
        if(ait->second > 0) {
            if(ait->second >= b[op(ait->first)]) {
                boo += b[op(ait->first)];
                a[ait->first] -= b[op(ait->first)];
                b[op(ait->first)] = 0;
            }
            else {
                boo += a[ait->first];
                b[op(ait->first)] -= a[ait->first];
                a[ait->first] = 0;
            }
        }
    }

    printf("%d %d\n",yay,boo);
    return 0;
}