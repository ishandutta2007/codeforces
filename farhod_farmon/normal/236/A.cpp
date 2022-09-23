#include <iostream>
using namespace std;
int main ()
{
int a[1000],n,i,j,d,c=1;
string s;
cin>>s;
n=s.size();
for(i=0; i<n; i++)
{
for(j=0; j<n-1; j++)
{
if(s[j]>s[j+1]){d=s[j]; s[j]=s[j+1]; s[j+1]=d;}
}
}

for(j=0; j<n-1; j++)
{
if (s[j] != s[j+1]) {c++;}
}
if(c%2==0){cout<<"CHAT WITH HER!";}
else {cout<<"IGNORE HIM!";}
return 0;
}