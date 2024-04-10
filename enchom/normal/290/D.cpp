#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

string SmallLetters(string a)
{
    Int i;
    
    for (i=0;i<a.length();i++)
    {
        if (a[i]>='A' && a[i]<='Z')
        {
            a[i]=(char)( (Int)a[i]+((Int)'a'-(Int)'A') );
        }
    }
    return a;
}

int main()
{
    string a;
    string newword;
    Int k;
    Int i;
    char ch;
    
    newword.clear();
    
    cin>>a;
    cin>>k;
    
    a=SmallLetters(a);
    
    for (i=0;i<a.length();i++)
    {
        ch=a[i];
        
        if ( (Int)ch < k+97 )
        {
            newword=newword+(char)((Int)ch-((Int)'a'-(Int)'A'));
        }
        else
        {
            newword=newword+ch;
        }
    }
    cout<<newword<<endl;
    
    return 0;
}