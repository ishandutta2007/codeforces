# include <iostream>
# include <vector>

using namespace std;

int count(char c, int n, int x) {
    if (c == '&') return n & x;
    else if (c == '|') return n | x;
    else return n ^ x;
}
int main() {
    int n;
    cin >> n;
    vector <pair <char, int>> to_do(n);
    for (int i = 0; i < n; ++i) cin >> to_do[i].first >> to_do[i].second;
    int start1 = 0;
    int start2 = 1023;
    for (int i = 0; i < n; ++i) {
        start1 = count(to_do[i].first, start1, to_do[i].second);
        start2 = count(to_do[i].first, start2, to_do[i].second);
    }
    int xorr = 0;
    int andd = 1023;
    int orr = 0;
    for (int i = 0; i < 10; ++i) {
        int c1 = (start1 >> i) & 1;
        int c2 = (start2 >> i) & 1;
        if (c1 == 0 && c2 == 0) andd &= ~(1<<i);
        if (c1 == 0 && c2 == 1) andd |= (1<<i);
        if (c1 == 1 && c2 == 0) xorr |= (1<<i);
        if (c1 == 1 && c2 == 1) orr |= (1<<i);
    }
    cout << 3 << endl;
    cout << "& " << andd << endl;
    cout << "| " << orr << endl;
    cout << "^ " << xorr << endl;
}