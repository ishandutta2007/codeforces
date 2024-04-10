#include<cstdio>  
#include<cstring>  
#include<iostream>  
using namespace std;  
const int maxn=2010;  
char str[maxn];  
int n,a[maxn];  
int main()  
{  
    while(scanf("%d",&n)!=EOF)  
    {  
    scanf("%s",str);  
    memset(a,0,sizeof(a));  
    int len=strlen(str),count=3;  
    for(int i=3;i<len;i++)  
    {  
        if(str[i-1]==str[i-2]&&str[i-1]==str[i-3])  
        {  
        int index=count%n;  
        a[index]++;  
        }  
        count++;  
    }  
    printf("%d\n",a[0]);  
    }  
    return 0;  
}