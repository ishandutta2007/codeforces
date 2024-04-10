#include<iostream>
using namespace std;
int main()
{
    int i;
    string s1,s2;
    bool b;
    cin>>s1;
    cin>>s2;
    b=0;
    if (s1.length()==s2.length())
    {
        b=1;
        for(i=0;i<s1.length();i++)
            {
                if(s1[i]!=s2[s2.length()-i-1])
                    {
                        b=0;
                        break;
                    }
            }
    }
    if(b==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}