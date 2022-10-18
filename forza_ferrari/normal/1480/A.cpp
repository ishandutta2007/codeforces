#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        n=s.length();
        for(register int i=0;i<n;++i)
        {
            if(i&1)
                s[i]=s[i]=='z'? 'y':'z';
            else
                s[i]=s[i]=='a'? 'b':'a';
        }
        cout<<s<<endl;
    }
    return 0;
}