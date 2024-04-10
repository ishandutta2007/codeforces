#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

#define pb push_back
#define fi first
#define se second

using namespace std;
int main()
{
    string s;
    int i,j,a=999999;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
         if( (s[i]-48)%2==0 && s[s.size()-1]>s[i] ){
             a=i;
             break;    
         }     
         else if( (s[i]-48)%2==0 )a=i;
    }
    if( a==999999 ){
        cout<<-1;
        return 0;    
    }
    swap( s[a], s[s.size()-1] );
    cout<<s;
    //system ( "pause" );
    return 0;    
}