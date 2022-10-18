#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;s[i];++i){
        if (s[i]!='A' && s[i]!='O' && s[i]!='I' && s[i]!='U' && s[i]!='E' && s[i]!='Y' &&
            s[i]!='a' && s[i]!='o' && s[i]!='i' && s[i]!='u' && s[i]!='e' && s[i]!='y') {
                cout<<'.'<<(char)tolower(s[i]);
            }
    }
    return 0;
}