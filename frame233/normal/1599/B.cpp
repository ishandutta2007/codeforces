#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}

void work()
{
	int n=read(),a=read(),b=read();
	char s[10]; scanf("%s",s);
	int da=s[0]=='l';
	scanf("%s",s);
	int db=s[0]=='l';
	if(a==0) da=1;
	if(a==n-1) da=0;
	if(b==0) db=1;
	if(b==n-1) db=0;
	if(a==b)
	{
		if(a==0) return (void)printf("%lld\n",n-1);
		if(a==n-1) return (void)printf("%lld\n",0LL);
		if(da==db)
		{
			if(da==0) return (void)printf("%lld\n",0LL);
			else return (void)printf("%lld\n",n-1);
		}
		else
		{
			if(da==1) return (void)printf("%lld\n",0LL);
			else return (void)printf("%lld\n",n-1);
		}
	}
	if(a<b) printf("%lld\n",((a+b)&1)?0:n-1);
	else printf("%lld\n",((a+b)&1)?n-1:0);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}