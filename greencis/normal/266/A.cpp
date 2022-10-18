#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    int res=0;
    char curS = s[0];
    for (int i = 1; i < s.length();++i){
        if (s[i]==curS) ++res;
        else curS = s[i];
    }
    cout<<res;
    return 0;
}