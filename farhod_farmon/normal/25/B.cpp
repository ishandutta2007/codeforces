#include <iostream>
using namespace std;
int main()
{
    int a,b=0,i;
    string s;
    cin>>a>>s;
    if( a%2!=0 ){
        cout<<s[0]<<s[1]<<s[2];    
        b=3;
    }
    else{
        cout<<s[0]<<s[1];
        b=2;     
    }
    for( i=b; i<s.size(); i++ ){
         if( i%2==b%2 ){
             cout<<"-";    
         }     
         cout<<s[i];
    }
    return 0;
}