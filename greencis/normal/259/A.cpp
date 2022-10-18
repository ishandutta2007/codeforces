#include <iostream>

using namespace std;

string s;

int main()
{
    int n = 8;
    while (n--) {
        cin >> s;
        if (s != "WBWBWBWB" && s!="BWBWBWBW") {cout <<"NO";return 0;}
    }cout<<"YES";

    return 0;
}