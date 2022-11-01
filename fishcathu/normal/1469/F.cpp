#include<bits/stdc++.h>
#define l first
#define r second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
int a[N],b[N*3];
priority_queue<pii,vector<pii>,greater<pii> >q;
void push(int l,int r)
{
	q.push(mk(l,r));
	++b[l];
	--b[r+1];
}
int solve()
{
	int n=read(),m=read();
	ll s=1-2*n;
	for(int i=1;i<=n;++i)s+=a[i]=read();
	if(s<m)return -1;
	sort(a+1,a+1+n,greater<int>());
	push(0,0);
	for(int i=1;i<=n;++i)
	{
		pii t=q.top();
		q.pop();
		--b[t.l];
		++b[t.l+1];
		push(t.l+2,t.l+1+(a[i]-1)/2);
		push(t.l+2,t.l+1+a[i]/2);
		if(t.l!=t.r)q.push(mk(t.l+1,t.r));
		int x=q.top().l;
		if(b[x]*2+b[x+1]>=m)break;
	}
	int i=q.top().l-1;
	s=0;
	while(s<m)
	{
		++i;
		b[i]+=b[i-1];
		s+=b[i];
	}
	return i;
}
int main()
{
	write(solve());
}