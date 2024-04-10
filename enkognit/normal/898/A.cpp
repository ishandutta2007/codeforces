#include <bits/stdc++.h>

using namespace std;

long long n,m,i,j,k,l;

int main()
{
 //freopen("number.in","r",stdin);
 //freopen("number.out","w",stdout);
 cin >> n;
 m=n/10;
 if (n%10>5) m++;
 cout << m*10;
}

/* cin >> n;
    cin >> a[1];
    k=1;
    for (i=1;i<=a[1];i++) s2+='a';
    for (i=2;i<=n;i++)
    {
     cin >> a[i];
     if (a[i]>a[i-1]) s1=s2+'a'; else
     if (a[i]<=a[i-1])
     {
      char c='z';
      int h;
      for (j=0;j<a[i];j++)
      {
       s1+=s2[j];
       if (s2[j]<=c) {c=s2[j];h=j;}
      }
      s1[h]++;
      k=max(c-95,k);
     }
     s2=s1;s1="";
    }
    cout << k << endl;
    return 0;*/