#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
char s[N];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    puts("3");
    puts("L 2");
    puts("R 2");
    printf("R %d\n",2*n-1);
    return 0;
}