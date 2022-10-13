#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<utility>
#include<set>
#include<sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
      string a[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main()
{
   int n,x,i=1;
   cin >> n;
   while (1)
   {
     if (n>i*5) n-=i*5;
     else break;
     i*=2;
   }
   x=(n-1)/i;
   cout << a[x] << endl;
   return 0;
}