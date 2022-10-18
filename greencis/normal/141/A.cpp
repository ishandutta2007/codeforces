#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    char s1[1000],s2[1000],s3[1000];
    cin>>s1>>s2>>s3;
    strcat(s1,s2);
    sort(s1,s1+strlen(s1));
    sort(s3,s3+strlen(s3));
    cout << (strcmp(s1,s3)==0?"YES":"NO");
    return 0;
}