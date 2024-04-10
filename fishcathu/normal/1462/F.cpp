#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef long long ll;
const int N=2E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
pair<int,int>a[N];
priority_queue<int,vector<int>,greater<int>>q;
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;++i)a[i].l=read(),a[i].r=read();
		sort(a+1,a+1+n);
		while(!q.empty())q.pop(); 
		for(int i=1;i<=n;++i)
		{
			while(!q.empty()&&q.top()<a[i].l)q.pop();
			int t=q.size()+lower_bound(a+i+1,a+1+n,make_pair(a[i].r+1,0))-a-i;
			ans=max(ans,t);
			q.push(a[i].r);
		}
		write(n-ans);
		putchar('\n');
	}
}