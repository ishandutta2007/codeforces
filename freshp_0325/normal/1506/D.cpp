#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
typedef long long LL;
typedef pair<int,int> P;
#define mp make_pair
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int n,a[200005],b[200005],ton[200005];
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	a[i]=b[i]=read(),ton[i]=0;
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i)	++ton[a[i]=lower_bound(b+1,b+1+len,a[i])-b];
	multiset<int> S;
	for(int i=1;i<=len;++i)	S.insert(ton[i]);
	int ans=0;
	while(int(S.size())>=2)
	{
		auto it1=prev(S.end()),it2=prev(it1);
		int st1=*it1,st2=*it2;
		S.erase(prev(S.end())),S.erase(prev(S.end()));
		++ans,--st1,--st2;
		if(st1)	S.insert(st1);
		if(st2)	S.insert(st2);
	}
	write(n-2*ans),puts("");
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}