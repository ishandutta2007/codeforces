#include<bits/stdc++.h>
using namespace std;
#define For(i,x,y)for(i=x;i<=y;i++)
#define Down(i,x,y)for(i=x;i>=y;i--)
struct node
{
    	int l,r;
	bool rem;
}a[105];
string s;
int main()
{
    	    int len,i,j,k=0;
	cin>>len>>s;
	len--;
	For(i,0,len)a[i].l=i-1,a[i].r=i+1;
        	a[len].r=-1;
	Down(j,25,0)
	{
		For(i,0,len)
		if(!a[i].rem&&s[i]-'a'==j)if(~a[i].l&&s[a[i].l]-'a'==s[i]-'a'-1)
		{
        			a[a[i].l].r=a[i].r;
        			if(~a[i].r)a[a[i].r].l=a[i].l;
			a[i].rem=1;
		}
		else if(~a[i].r&&s[a[i].r]-'a'==s[i]-'a'-1)
		{
			if(~a[i].l)a[a[i].l].r=a[i].r;
			a[a[i].r].l=a[i].l;
			a[i].rem=1;
		}
		Down(i,len,0)
		if(!a[i].rem&&s[i]-'a'==j)if(~a[i].l&&s[a[i].l]-'a'==s[i]-'a'-1)
        		{
			a[a[i].l].r=a[i].r;
			if(~a[i].r)a[a[i].r].l=a[i].l;
			a[i].rem=1;
	            	}
		else if(~a[i].r&&s[a[i].r]-'a'==s[i]-'a'-1)
		{
			if(~a[i].l)a[a[i].l].r=a[i].r;
			a[a[i].r].l=a[i].l;
			a[i].rem=1;
		}
	}
	For(i,0,len)k+=a[i].rem;
        	cout<<k;
	return 0;
}