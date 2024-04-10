#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int a,b,d[101],e,f,g,h,i,j,k,cnt=0,ans=0;
int c;

int main()
{
    string s;
    map < char, int > m;
    cin>>s;
    for( i=0; i<s.size(); i++ ){
         m[s[i]]++;     
    }
    cout<<min( min(m['e']/3, (m['n']-1)/2), min(m['i'], m['t']) );    
    //system( "pause" );
    return 0;    
}