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
#define ll long long
#define inf 1000000000
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
int ax1,ay1,ax2,ay2;
int query(int x,int y)
{
	printf("? %d %d\n",x,y);
#ifdef wasa855
	int minn=2e9;
	for(int i=ax1;i<=ax2;i++) for(int j=ay1;j<=ay2;j++) minn=min(minn,abs(i-x)+abs(j-y));
	return minn;
#endif
	fflush(stdout);
	return read();
}
signed main()
{
#ifdef wasa855
	cin>>ax1>>ay1>>ax2>>ay2;
#endif
	int A=query(1,1),B=query(1,inf),C=query(inf,1),D=query(inf,inf);
	int res=1;
	for(int i=29;i>=0;i--)
	{
		if(res+(1<<i)>inf) continue;
		int cur=query(res+(1<<i),1);
		if(cur==A+1-res-(1<<i)) res+=1<<i;
	}
	int x1=res,y1=A-(x1-1)+1,x2=inf-(C-(y1-1)),y2=inf-(D-(inf-x2));
	printf("! %d %d %d %d\n",x1,y1,x2,y2);
	return 0;
}