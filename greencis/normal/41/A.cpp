#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char a[110],b[110];
    cin>>a>>b;
    reverse(a,a+strlen(a));
    cout<<(strcmp(a,b)==0?"YES":"NO");
    return 0;
}