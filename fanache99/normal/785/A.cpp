//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'T')
            answer += 4;
        if (s[0] == 'C')
            answer += 6;
        if (s[0] == 'O')
            answer += 8;
        if (s[0] == 'D')
            answer += 12;
        if (s[0] == 'I')
            answer += 20;
    }
    cout << answer << "\n";
    return 0;
}