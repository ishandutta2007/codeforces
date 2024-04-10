#include<bits/stdc++.h>
using namespace std;
const int N=5E3+1;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 

int main()
{
    for(int t=read();t--;)
    {
    	int n=read(),k=n>>1,s=0;
    	while(n--)if(read())++s; 
    	if(s<=k)s=0;
    	else 
    	{
    		s=1;
    		if(k&1)++k;
		}
    	printf("%d\n",k);
    	while(k--)printf("%d%c",s,k?' ':'\n');
	}
}