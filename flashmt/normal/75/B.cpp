#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

struct rec { string s; int d;};

string s;
rec a[222];
int m,n,d[222];

int find()
{
    int i;
    fr(i,1,n)
      if (a[i].s==s) return i;
    return 0;
}

bool cmp(rec i,rec j)
{
    return i.d>j.d || (i.d==j.d  && i.s<j.s);
}

int main()
{
    int i,j,k;
    cin >> a[1].s; n=1; a[1].d=-1000000;
    cin >> m;
    while (m--)
    {
       cin >> s;
       i=find();
       if (!i) a[++n].s=s,i=n;
       cin >> s;
       if (s=="likes")
       {
          cin >> s; 
          s.erase(s.length()-2,2);
          j=find(); 
          if (!j) a[++n].s=s, j=n;
          if (i==1) a[j].d+=5;
          if (j==1) a[i].d+=5;
          cin >> s;           
       }
       else
       {
           if (s=="posted") k=15;
           else k=10;
           cin >> s;  cin >> s;
           s.erase(s.length()-2,2); 
           j=find(); 
           if (!j) a[++n].s=s, j=n;
           if (i==1) a[j].d+=k;
           if (j==1) a[i].d+=k;
           cin >> s;               
       }
    }
    sort(a+1,a+n+1,cmp);
    fr(i,1,n-1) cout << a[i].s << endl;
    return 0;
}