#include <iostream>

using namespace std;

int get_dow()
{
    string s; cin >> s;
    if (s == "monday") return 0;
    if (s == "tuesday") return 1;
    if (s == "wednesday") return 2;
    if (s == "thursday") return 3;
    if (s == "friday") return 4;
    if (s == "saturday") return 5;
    if (s == "sunday") return 6;
    return -1;
}

int main()
{
    int a = get_dow(), b = get_dow();
    int dif = (7 + a - b) % 7;
    if (dif == 0 || dif == 4 || dif == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}