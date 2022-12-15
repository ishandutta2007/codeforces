#include <bits/stdc++.h>
using namespace std;

#define SIZE 105
#define INF 0x3f3f3f

int main() {
    string s;
    cin >> s;
    int a = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s.substr(i, 3)  == "Ann") {
            a++;
        } else if(s.substr(i, 4) == "Olya") {
            a++;
        } else if(s.substr(i, 5) == "Slava") {
            a++;
        } else if(s.substr(i, 5) == "Danil") {
            a++;
        } else if(s.substr(i, 6) == "Nikita") {
            a++;
        } 
    }
    if(a == 1) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}