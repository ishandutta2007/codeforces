//#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

char s[1 + MAXN];
queue<int> first, second;

int main() {
    int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'D')
            first.push(i);
        else
            second.push(i);
    while (!first.empty() && !second.empty())
        if (first.front() < second.front()) {
            second.pop();
            first.push(first.front() + n);
            first.pop();
        }
        else {
            first.pop();
            second.push(second.front() + n);
            second.pop();
        }
    if (first.empty())
        cout << "R\n";
    else
        cout << "D\n";
    return 0;
}