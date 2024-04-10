#include <iostream>

using namespace std;

int main()
{
    string s1,s2;
    int idx=0;
    cin>>s1>>s2;
    for (int i = 0; i < s2.length();++i){
        if (s1[idx] == s2[i]) ++idx;
    }
    cout << idx+1;
    return 0;
}