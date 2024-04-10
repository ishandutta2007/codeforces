#include <iostream>
using namespace std;
int main()
{
    string s,t,farhod;

    cin>>s>>t;

    farhod=s;

    int i=s.size()-1,j;

    while( s[i]=='z' )i--;

    farhod[i]++;

    for( j=i+1; j<s.size(); j++ )farhod[j]='a';

    if( farhod<t )cout<<farhod;

    else cout<<"No such string";

    return 0;
}