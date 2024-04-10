#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <map>

#define w1 while(1)

using namespace std;

map <string,string> lang;

int main()
{
    int i,n,each;
    string str1,str2;
    scanf("%d %d",&n, &each);
    for(i=0;i<each;i++) {
         cin >> str1 >> str2;
         if(str2.size() < str1.size()) lang[str1] = str2;
         else lang[str1] = str1;
    }
    for(i=0;i<n;i++) {
         cin >> str1;
         cout << lang[str1] << " ";
    }
    return 0;
}