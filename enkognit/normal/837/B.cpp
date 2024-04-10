#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n,m,i,j,k,xB1,xB2,xR1,xR2,xG1,xG2,lB1=10000,lB2,rB1=10000,rB2,lR1=10000,lR2,rR1=10000,rR2,lG1=10000,lG2,rG1=10000,rG2;
string s;
short a[101][101];

int main()
{
 //freopen("papaya.in","r",stdin);
 //freopen("papaya.out","w",stdout);
 ios_base::sync_with_stdio(0);
 cin >> n >> m;
 for (i=1;i<=n;i++)
 {
  cin >> s;
  for (j=0;j<m;j++)
  {
   if (s[j]=='B')
   {
    a[i][j+1]=1;
    if (xB1==0) xB1=i;
    if (xB2==0) xB2=j+1;
    if (i<lB1) lB1=i;
    if (j+1<rB1) rB1=j+1;
    if (i>lB2) lB2=i;
    if (j+1>rB2) rB2=j+1;
   } else
   if (s[j]=='R')
   {
    a[i][j+1]=2;
    if (xR1==0) xR1=i;
    if (xR2==0) xR2=j+1;
    if (i<lR1) lR1=i;
    if (j+1<rR1) rR1=j+1;
    if (i>lR2) lR2=i;
    if (j+1>rR2) rR2=j+1;
   } else
   if (s[j]=='G')
   {
    a[i][j+1]=3;
    if (xG1==0) xG1=i;
    if (xG2==0) xG2=j+1;
    if (i<lG1) lG1=i;
    if (j+1<rG1) rG1=j+1;
    if (i>lG2) lG2=i;
    if (j+1>rG2) rG2=j+1;
   }
  }
 }
 for (i=lB1;i<=lB2;i++)
  for (j=rB1;j<=rB2;j++) if (a[i][j]!=1) {cout << "NO";exit(0);}
 for (i=lR1;i<=lR2;i++)
  for (j=rR1;j<=rR2;j++) if (a[i][j]!=2) {cout << "NO";exit(0);}
 for (i=lG1;i<=lG2;i++)
  for (j=rG1;j<=rG2;j++) if (a[i][j]!=3) {cout << "NO";exit(0);}
 if (lB2-lB1==lR2-lR1 && lB2-lB1==lG2-lG1 && lG2-lG1==lR2-lR1 &&
     rB2-rB1==rR2-rR1 && rB2-rB1==rG2-rG1 && rG2-rG1==rR2-rR1 &&
     ((xB1==xR1 && xB1==xG1 && xR1==xG1)||(xB2==xR2 && xB2==xG2 && xR2==xG2))) cout << "YES"; else
 cout << "NO";
 return 0;
}