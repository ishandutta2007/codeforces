#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
char s[xx];
char c[xx];
char ans[xx];
char l[xx];//
int n;
bool cmp(char *x,char *y)//x<=y
{
	for(int i=n+1;i>=1;i--)
	{
		if(x[i]>y[i])return 0;
		if(x[i]<y[i])return 1;
	}
	return 1;// 
}
void add(char *x)
{
	x[1]++;
	int now=1;
	while(x[now]=='2')x[now]='0',x[now+1]++,now++;
}
int main(){
	n=read();
	scanf("%s",s+1);
	scanf("%s",c+1);
	reverse(s+1,s+n+1);
	reverse(c+1,c+n+1);
	memcpy(l,s,sizeof(s));
	add(l);add(l);add(l);
	memcpy(ans,c,sizeof(c));
	if(cmp(l,c)&&c[1]=='0')ans[1]++;
	memset(l,0,sizeof(l));
	int chk=1;//sc 
	int fulls=1,fullc=1;//s 
	for(int i=n;i>=1;i--)
	{
		if(i==1)
		{
			if(chk)break;
			l[i]='1';
			if(l[2]=='0')l[1]='0';//41 
			if(cmp(ans,l))
			{
				memcpy(ans,l,sizeof(l));
			}
			break;
		}
		if(s[i]==c[i]&&s[i]=='1')
		{
			if(chk)//1 
			{
				l[i]='0';//11
				if(!fulls)//00
				{
					fullc=0;
				}
				continue;
			}
			l[i]='1';//01 
			//s1c0 
			//01 
			fullc=0;
			continue;
		}
		if(s[i]=='0'&&c[i]=='1')
		{
			if(!chk)//s1c0 
			{
				l[i]='1';
				fulls=fullc=0;
				continue;
			}
			else //01
			{
				l[i]='1';
				chk=0;continue;
			}
		}
		if(s[i]=='1'&&c[i]=='0')
		{
			l[i]='1';//1,0 
			continue;
		}
		if(s[i]=='0'&&c[i]=='0')
		{
			if(!fullc)//01
			{
				l[i]='1';
				chk=0;
				continue;
			}
			if(!chk)//10
			{
				l[i]='1';
				fulls=0;
				continue;
			}
			l[i]='0';//00
			if(!fullc)//11
			{
				fulls=0;
			}
		}
//		cout<<i<<" "<<chk<<"\n";
	}
	for(int i=n;i>=1;i--)cout<<ans[i];
	puts("");
	return 0;
}