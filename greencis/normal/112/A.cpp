#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[10000],b[10000];
    cin>>a>>b;
    for (int i = 0;i<strlen(a);++i){
        if (a[i]>='A'&&a[i]<='Z')
            a[i]+=32;
        if (b[i]>='A'&&b[i]<='Z')
            b[i]+=32;
    }
    cout<<strcmp(a,b) > 0?1:strcmp(a,b)<0?-1:0;
    return 0;
}