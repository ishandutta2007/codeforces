#include<iostream>
using namespace std;
int main()
{
    int i,p;
    char a[9]{'h','e','l','l','o','1','2','3','4'};
    string s;
    cin>>s;
    p=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]==a[p])
        {
  //          cout<<p<<endl;
  //          cout<<s[i];
            p+=1;
        }
    }
    if(p<5)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
    return 0;
}