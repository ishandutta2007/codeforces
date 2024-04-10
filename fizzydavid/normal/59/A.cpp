#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
using namespace std;
string a,b;
int cl,cu;
int main()
{
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='a'&&a[i]<='z')cl++;
        else if(a[i]>='A'&&a[i]<='Z')cu++;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='A'&&a[i]<='Z')b+=a[i]+(cl>=cu)*('a'-'A');
        else if(a[i]>='a'&&a[i]<='z')b+=a[i]-(cu>cl)*('a'-'A');
    }
    cout<<b;
    return 0;
}