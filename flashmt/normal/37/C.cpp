#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n,cur;
string re[1010],s;
vector < pair<int,int> > a;

void out()
{
   int i;
   cout << "YES" << endl;
   fr(i,1,n) cout << re[i] << endl;
   exit(0);
}

void visit(int x)
{
   char i;
   if (a[cur].first>x)
      fr(i,'0','1')
      {
         s+=i;
         visit(x+1);
         s.erase(s.size()-1,1);
      }
   else
   {
      re[a[cur++].second]=s;
      if (cur==n) out();
   }
}

int main()
{
   int i,x;
   cin >> n;
   fr(i,1,n) cin >> x, a.push_back(make_pair(x,i));
   sort(a.begin(),a.end());
   visit(0);
   cout << "NO" << endl;
   return 0;      
}