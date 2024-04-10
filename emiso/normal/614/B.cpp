#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isb(string st) {
    if(st[0] != '1') return false;
    for(int i=1;i<st.size();i++) {
        if(st[i] != '0') return false;
    }
    return true;
}

int main() {
    int n,z = 0,flag = 0;
    string str,mult = "1";

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> str;

        if(str[0] == '0') flag = 1;

        if(flag == 0) {
            if(isb(str)) z += (str.size() - 1);
            else mult = str;
        }
    }

    if(flag) printf("0\n");
    else {
        cout << mult;
        for(int i=0;i<z;i++)
            printf("0");
        puts("");
    }

    return 0;
}