#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
string s1,s2;
int a[256],b[256];
bool f;
int main()
{
    int i=0;
    getline(cin,s1);
    for(i=0;i<s1.size();i++)a[s1[i]]++;
    getline(cin,s2);
    for(i=0;i<s2.size();i++)b[s2[i]]++;
    for(i='A';i<='z';i++)
    {
        if(b[i]>a[i]){f=true;break;}
    }
    if(f==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}