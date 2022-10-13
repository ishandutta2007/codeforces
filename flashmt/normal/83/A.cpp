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

int main()
{
   int n,i,y=0,x,cnt=1;
   long long re=0;
   cin >> n >> x;
   fr(i,2,n)
   {
      y=x;
      scanf("%d",&x);
      if (x!=y)
      {
         re+=1LL*cnt*(cnt+1)/2;
         cnt=1; 
      }
      else cnt++;
   }
   re+=1LL*cnt*(cnt+1)/2;
   cout << re << endl;
   return 0;
}