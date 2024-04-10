#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

int n,k;
char a[100100];

int main()
{
	cin >> n >> k;
	scanf("%s",&a);
	while (k)
  {
    int kk=k;
    for (int i=0;i<n-1 && k;i++)
      if (a[i]=='4' && a[i+1]=='7')
      {
         if (i%2==0)
         {
            if (i+2<n && a[i+2]=='7')
            {
               if (k&1) a[i+1]='4';
               puts(a); 
               return 0;
            }
            a[i+1]='4'; k--;
         }
         else
         {
            if (i && a[i-1]=='4')
            {
               if (k&1) a[i]='7';
               puts(a); 
               return 0;
            }
            a[i]='7'; k--;
         }
      }
    if (k==kk) break;
  }	
  puts(a);
}