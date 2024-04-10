#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    string s,t;
    int i,cnt=0;
    map < char, int > ms,mt;
    char c[200];
    getline( cin, s );
    getline( cin, t );
    for( i=0; i<s.size(); i++ )ms[s[i]]++;
    for( i=0; i<t.size(); i++ ){
         if( mt[t[i]]==0 ){
             cnt++;
             c[cnt]=t[i];    
         }     
         mt[t[i]]++;
    }
    for( i=1; i<=cnt; i++ ){
         if( c[i]==' ' )continue;
         if( ms[c[i]]<mt[c[i]] ){
             cout<<"NO";
             return 0;
         }     
    }
    cout<<"YES";
   // system ( "pause" );
    return 0;
}