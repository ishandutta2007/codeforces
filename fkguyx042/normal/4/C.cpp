#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int>mp;
string s;
int n;
int main()
{
    scanf("%d",&n);
    for (;n--;)
    {
    	  cin>>s;
    	  if (!mp[s]) puts("OK"),mp[s]++;
    	  else 
    	  {
    	  	 cout<<s;
    	  	 printf("%d\n",mp[s]++);
    	  }
    }
}