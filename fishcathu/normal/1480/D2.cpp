#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],w[N];
int main()
{
	int ans=0;
	for(int n=read(),s=0,las=0;n--;)
	{
		int t=read();
		if(!w[t]&&las!=t)
		{
			a[++s]=t;
			w[t]=s;
			++ans;
			continue;
		}
		if(w[t]==s)continue;
		for(int i=1;i<=s;++i)w[a[i]]=0;
		if(las!=t)las=a[s],a[1]=t;
		else a[1]=a[s];
		w[a[1]]=1;
		s=1;
	}
	write(ans,'\n');
}