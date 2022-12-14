#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<map>
#define ll long long
#define INF 2000000000
using namespace std;

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll n;
int s[100010];
int x[100010],cnt=0;
map<int,bool> mp;
int main()
{ 
    n=read();
    for(int i=1;i<=n;i++)
    {
    	s[i]=read();
    	if(!mp[s[i]])
    	{
    		mp[s[i]]=1;
    		x[++cnt]=s[i];
    	}
    }
	if(cnt==1)
	{
		cout<<"YES";
	}	
    else
        if(cnt==2)
        {
        	cout<<"YES";
        }
        else 
        if(cnt==3)
		{
        	if(abs(x[1]-x[2])==abs(x[2]-x[3]))
        	    cout<<"YES";
        	else if(abs(x[1]-x[3])==abs(x[2]-x[3]))
        	    cout<<"YES";
        	else if(abs(x[1]-x[3])==abs(x[2]-x[1]))
        	    cout<<"YES";
            else   cout<<"NO";
        }
        else
            cout<<"NO";
	return 0;
}