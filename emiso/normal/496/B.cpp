#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    int i,n;
    string str,str2;
    scanf("%d",&n);
    cin >> str;
    string mini = str;
    
    for(i=0;i<10;i++) {
         for(int j=0;j<n;j++) {
                 if(str[j] == '9') str[j] = '0';
                 else str[j]++;
         }
         str2 = str;
         for(int j=0;j<n;j++) {
                 mini = min(str2,mini);
                 char oi = str2[0];
                 str2.erase(str2.begin()); 
                 str2 += oi;
         }
         mini = min(str2,mini);
    }
    cout << mini;
    return 0;
}