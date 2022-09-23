#include <iostream>
using namespace std;
int main()
{
    int a,i,cnt=0;
    string s;
    cin>>a>>s;
    i=a;
    while( i<s.size() ){
           if( s[i-1]==s[i-2] && s[i-1]==s[i-3] ){
               cnt++;    
           }       
           i+=a;
    }
    cout<<cnt;
    return 0;    
}