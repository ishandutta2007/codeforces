#include<iostream>  
#include<cstdio>  
#include <algorithm>  
#include <cstring>  
#include <set>  
using namespace std;  
int a[120];  
int main()  
{  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<n;i++){  
        scanf("%d",&a[i]);  
    }  
    if(a[0]%2==0||a[n-1]%2==0) printf("No");  
   else  if(n%2==0) printf("No");  
    else  printf("Yes");  
    return 0;  
}