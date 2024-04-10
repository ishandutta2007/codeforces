#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string s;

    cin>>s;

    int ld = s.back() - '0';

    printf("%d\n",ld%2);

    return 0;
}