#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
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
char s[100010];
int op[5];
int main()
{
	cin.getline(s,100010);
	op[1]=op[2]=op[3]=op[4]=0;
	if(strlen(s)%2==0)
	{
	    for(int i=0;i<strlen(s);i++)
	    {
	         switch(s[i])
			 {
			 	case('U'):
			 		{
			 			op[1]++;
			 	        break;
					}
				case('D'):
					{
						op[2]++;
						break;
				    }
				case('L'):
					{
						op[3]++;
						break;
					}
				case('R'):
					{
						op[4]++;
						break;
					}
			 }	
	    }
	    cout<<(abs(op[1]-op[2])+abs(op[3]-op[4]))/2;
    }
    else
        cout<<"-1";
	return 0;
}