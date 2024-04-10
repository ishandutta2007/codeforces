#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

int n;
char s[105];
int main()
{
   	n=read();
   	scanf("%s",s);
    bool yes=false;
	for(int i=0;i<n;)
   	{
		yes=false;
        if(s[i]=='o')
        {
		    while(i+2<n&&s[i+1]=='g'&&s[i+2]=='o')
			{
			    yes=true;
				i+=2;	
			}
			if(yes) printf("***");
		}
		if(!yes)
		   printf("%c",s[i]);
		i++;
	}
}