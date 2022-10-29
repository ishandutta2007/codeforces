#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    unsigned int i;
    int len=0,c=0;
    string ch,ch2;
    cin>>ch;
    len=ch.length();
    for(i=0;i<len;i++)
    {
            if(    (ch[i]!='A' && ch[i]!='a')
                && (ch[i]!='E' && ch[i]!='e') 
                && (ch[i]!='I' && ch[i]!='i') 
                && (ch[i]!='O' && ch[i]!='o')
                && (ch[i]!='U' && ch[i]!='u')
                && (ch[i]!='Y' && ch[i]!='y')   )
            {
                if(isupper(ch[i]))
                {ch2+=ch[i]+32;c++;}
                else
                {ch2+=ch[i];c++;}
            }
           
    }
    for(i=0;i<c;i++)
    {
        cout<<"."<<ch2[i];
    }
    return 0;
}