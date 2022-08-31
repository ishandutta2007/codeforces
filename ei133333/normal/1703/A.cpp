#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        for(auto& c : S) c = tolower(c);
        if(S == "yes") cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}