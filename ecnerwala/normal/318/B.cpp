#include<iostream>
#include <string>

#include<cstring>

using namespace std;

int main() {
    string S; cin >> S;
    long long out = 0, numH = 0;//out is total count, numH is number of heavy's 
    for (int i=0; i+5<=S.length(); i++) {
        string s = S.substr(i, 5);
        if (s == "heavy") {
            numH++;
        }
        else if (s == "metal") {
            out += numH;
        }
    }
    cout << out << '\n';
    return 0;
}