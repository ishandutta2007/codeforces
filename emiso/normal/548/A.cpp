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

int ispalin(string s) {
    int j=0,k;
    k = s.size()-1;
    while(j<k) {
           if(s[j]!=s[k]) return 0;
           j++;
           k--;    
    }
}

int main()
{
    int k,l,le,flag=1;
    string s;
    cin >> s >> k;
    l = s.size();
    le = l/k;
    if(l%k != 0) flag=0;
    for(int i=0;i<k;i++) {
         if(!ispalin(s.substr(i*le,le))) flag = 0;
    }
    if(flag) cout << "YES";
    else cout <<"NO";
    return 0;
}