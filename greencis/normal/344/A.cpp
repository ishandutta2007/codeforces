#include <iostream>

using namespace std;

int main()
{
    int n,res=0;
    string s1="",s2="";
    cin>>n;
    while (n--) {
        s1 = s2;
        cin >> s2;
        if (s2 != s1) ++res;
    }
    cout << res;
    return 0;
}