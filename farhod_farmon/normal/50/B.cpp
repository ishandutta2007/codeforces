#include <iostream>
using namespace std;
int main()
{
    string s;
    long long int i,cnt=0,m[300]={};
    cin>>s;
    for( i=0; i<s.size(); i++ )m[s[i]]++;
    for( i=1; i<=256; i++ )cnt+=m[i]*m[i];
    cout<<cnt;
    return 0;
}