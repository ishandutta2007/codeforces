#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        cout << set< char >(S.begin(), S.end()).size() + S.size() << endl;
    }
}