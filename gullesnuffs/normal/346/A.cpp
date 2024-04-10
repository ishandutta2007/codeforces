#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int a[1000];

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

int main()
{
    int n;
    scanf("%d", &n);
    int g, m=0;
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        if(!i)
            g=a[i];
        else
            g=gcd(g, a[i]);
        if(a[i] > m)
            m=a[i];
    }
    if((m/g-n)%2)
        printf("Alice\n");
    else
        printf("Bob\n");
    return 0;
}