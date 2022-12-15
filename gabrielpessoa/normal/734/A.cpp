#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = count(s.begin(), s.end(), 'A');
    int d = n - a;
    if(a > d) {
        puts("Anton");
    } else if(a < d) {
        puts("Danik");
    } else {
        puts("Friendship");
    }
    return 0;
}