#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a=0, d=0;
    string str;

    cin >> n >> str;
    for(int i=0; i<n;i++) {
        if(str[i] == 'A') a++;
        else if(str[i] == 'D') d++;
    }

    if(a > d) printf("Anton\n");
    else if(d > a) printf("Danik\n");
    else printf("Friendship\n");

    return 0;
}