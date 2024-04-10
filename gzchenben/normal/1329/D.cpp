#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,c[200005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	while(x<=n+1)
	{
		c[x]+=y;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void print(int x,int y)
{
//	printf("%d %d\n",x,y-1);
	int xx=x-sum(x),yy=y-sum(y);
	printf("%d %d\n",xx,yy-1);
	add(y,yy-xx);
//	printf("add:%d %d\n",y,yy-xx);
}
struct node
{
	char ch;
	int pos;
};
vector<node> vec;
node stk[200005];
int t,top,cnt[30];
char s[200005];
bool check(char x,char y)
{
	char mx='z'+1;
	int sum=0;
	for(int i=0;i<26;i++)
	{
		if(cnt[mx-'a']<=cnt[i]) mx=i+'a';
		sum+=cnt[i];
	}
//	printf("%d %c\n",sum,mx);
	if((sum+1)/2-1>=cnt[mx-'a'] || mx==x || mx==y)
	{
		cnt[x-'a']--;
		cnt[y-'a']--;
		return true;
	}
	return false;
}
void calc()
{
	char mx='z'+1;
	int sum=0;
	for(int i=0;i<26;i++)
	{
		if(cnt[mx-'a']<=cnt[i]) mx=i+'a';
		sum+=cnt[i];
	}
	printf("%d\n",max((sum+1)/2,cnt[mx-'a'])+1);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		vec.clear();
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]) 
			{
				vec.push_back((node){s[i],i});
				cnt[s[i]-'a']++;
			}
		}
		calc();
		for(int i=0;i<vec.size();i++)
		{
			if(top==0 || vec[i].ch==stk[top].ch)
			{
				stk[++top]=vec[i];
				continue;
			}
			if(!check(vec[i].ch,stk[top].ch))
			{
				stk[++top]=vec[i];
				continue;
			}
			else
			{
				print(stk[top].pos,vec[i].pos);
				top--;
			}
		}
		while(top>=1)
		{
			print(stk[top].pos,stk[top].pos+1);
			top--;
		}
		print(1,n+1);
		memset(cnt,0,sizeof(cnt));
		memset(c,0,sizeof(int)*(n+2));
	}
}