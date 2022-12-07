#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=510;
int a[M],n;
map<int,int>t;
vector<int>ans1;
vector<pii>ans2;

void flip(int l,int r)
{
	int len=r-l+1;
	for (int i=1;i*2<=len;i++)swap(a[i+l-1],a[r-i+1]);
}

void solve()
{
	t.clear();ans1.clear(),ans2.clear();
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),t[a[i]]++;
	for (int i=1;i<=n;i++)
		if (t[a[i]]&1)return puts("-1"),void();
	int l=1;
	for (int i=1;i<=n;i+=2)
	{
		int pos=-1;
		for (int j=i+1;j<=n;j++)
			if (a[j]==a[i]){pos=j;break;}
		if (pos==i+1){ans1.pb(2);l+=2;continue;}
		int dis=pos-i;
		for (int j=1;j<=dis;j++)
			ans2.pb(mp(l+dis+j-2,a[j+i-1]));
		l+=2*dis;ans1.pb(dis*2);
		flip(i,i+dis-1);
		for (int j=1;j<=dis+1;j++)
			ans2.pb(mp(l+dis+j-1,a[j+i-1]));
		flip(i,i+dis);
		l+=2*dis+4,ans1.pb((dis+1)*2);ans1.pb(2);
	}
	cout<<ans2.size()<<endl;
	for (auto x:ans2)cout<<x.x<<' '<<x.y<<'\n';
	cout<<ans1.size()<<endl;
	for (auto x:ans1)cout<<x<<' ';
	puts("");
}

signed main()
{
	WT solve();
	return 0;
}
/*
1
6
1 3 1 2 2 3

*/