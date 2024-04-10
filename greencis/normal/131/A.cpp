#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    bool wrong = true;
    for (int i = 1; i < s.length();++i)
        if (!(s[i]>='A'&&s[i]<='Z'))
        {
            wrong=false;
            break;
        }
    if(wrong){
        for (int i = 0; i < s.length();++i){
            if (s[i]>='A' && s[i]<='Z') {
                s[i]  +=32;
            }
            else s[i]-=32;
        }
    }
    cout<<s;
    return 0;
}