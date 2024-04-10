//////Bokan ga bokka--nn!!
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int main()
////{
////	string s;
////	cin >> s;
////	int id;
////	for(int i=0;i<s.size();i++)
////	{
////			if(s[i]=='^') id=i;
////	}
////	ll val=0;
////	for(int i=0;i<s.size();i++)
////	{
////			if(1<=s[i]-'0' && s[i]-'0'<=9)
////			{
////				val+=((id-i)*(s[i]-'0')*1ll);
////			}
////	}
////	if(val>0ll) puts("left");
////	else if(val<0ll) puts("right");
////	else puts("balance");
//
////}
//
//////Bokan ga bokka--nn!!
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int val[105]={};
////int main()
////{
////	int n,m;
////	s(n);  s(m);
////	for(int i=0;i<m;i++)
////	{
////			int a,b,c;
////			scanf("%d %d %d",&a,&b,&c);
////			val[a]+=c;
////			val[b]-=c;
////	}
////	for(int i=1;i<=n;i++) val[i]=abs(val[i]);
////	int ret=0;
////	for(int i=1;i<=n;i++) ret+=val[i];
////	printf("%d\n",ret/2);
////}
//
//////Bokan ga bokka--nn!!
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////char f[5005][5005];
////int v[5005]={};
////int main()
////{
////	int n,m;
////	scanf("%d %d",&n,&m);
////	for(int i=0;i<n;i++)
////	{
////			scanf("%s",f[i]);
////	}
////	for(int i=0;i<m;i++)
////	{
////
////
//////Bokan ga bokka--nn!!
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int pos[10][6];
////int ex[10][10][6];
////int main()
////{
////	string s;
////	cin >> s;
////	for(int i=0;i<10;i++)for(int j=0;j<6;j++)pos[i][j]=-1;
////	for(int i=0;i<10;i++)for(int k=0;k<10;k++) for(int j=0;j<6;j++)ex[i][k][j]=-1;
////	int v=0;
////	for(int i=0;i<s.size();i++)
////	{
////			pos[s[i]-'0'][(s.size()-1-i)%6]=i;
////			v=(v*10+s[i]-'0')%7;
////	}
////	int m[6]={1,3,2,6,4,5};
////	for(int i=0;i<10;i++)
////	{
////			for(int j=0;j<10;j++)
////			{
////					for(int k=0;k<6;k++)
////					{
////						for(int l=k;l<6;l++)
////						{
////								if(pos[i][k]==-1 || pos[j][l]==-1) continue;
////								//printf("%d %d %d %d %d\n",i,j,k,l,v);
////								ex[i][j][l-k]=true;
////								int f=1;
////								for(int ii=0;ii<l-k;ii++) f*=10;
////								f--;
////								f*=(i-j);
////								f*=m[k];
////								if((v+f)%7==0)
////								{
////										swap(s[pos[i][k]],s[pos[j][l]]);
////										cout << s << endl;
////										return 0;
////								}
////						}
////					}
////			}
////	}
////	puts("0");
////}
//
//////Bokan ga bokka--nn!!
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int main()
////{
////	int v[10]={},cur=0;
////	string s; cin >> s;
////	for(int i=0;i<s.size();i++) v[s[i]-'0']++;
////	for(int i=1;i<=9;i++)
////	{
////		for(int j=1;j<v[i];j++)
////		{
////			cur=(cur*10+i)%7;
////			printf("%d",i);
////		}
////	}
////	int vv[4]={1,6,8,9};
////	do
////	{
////		int d=0;
////		for(int i=0;i<4;i++)
////		{
////			d=(d*10+vv[i]);
////		}
////		d%=7;
////		if((cur+d)%7==0)
////		{
////			for(int i=0;i<4;i++) printf("%d",vv[i]);
////			for(int i=0;i<v[0];i++) printf("0");
////			return 0;
////		}
////	}while(next_permutation(vv,vv+4));
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int main()
////{
////	int a,b;
////	int c=0,d=0,e=0;
////	cin >> a >> b;
////	for(int i=1;i<=6;i++)
////	{
////			if(abs(i-a)<abs(i-b)) c++;
////			if(abs(i-a)==abs(i-b)) d++;
////			if(abs(i-a)>abs(i-b)) e++;
////	}
////
////	cout << c << " " <<  d  << " " << e << endl;
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int a[100005],b[100005];
////bool ok[100005][2]={};
////int all[200005];
////int main()
////{
////	int n;
////	scanf("%d",&n);
////	for(int i=0;i<n;i++)
////	{
////		scanf("%d %d",&a[i],&b[i]);
////		all[i*2]=a[i]; all[i*2+1]=b[i];
////	}
////	sort(all,all+2*n);
////	int v=all[n-1];
////	for(int i=0;i<n;i++)
////	{
////		if(v>=a[i]) ok[i][0]=true;
////		if(v>=b[i]) ok[i][1]=true;
////	}
////	for(int i=0;2*(i+1)<=n;i++)
////	{
////			ok[i][0]=true;
////			ok[i][1]=true;
////	}
////	for(int i=0;i<2;i++)
////	{
////			for(int j=0;j<n;j++)
////			{
////					printf("%d",ok[j][i]);
////			}
////			puts("");
////	}
////	cin >> n;
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////char f[505][505];
////bool ok[505][505]={};
////int main()
////{
////	int n,m,k;
////	scanf("%d %d %d",&n,&m,&k);
////	for(int i=0;i<n;i++)
////	{
////			scanf("%s",&f[i]);
////	}
////	if(!k)
////	{
////			for(int i=0;i<n;i++) printf("%s\n",f[i]);
////			return 0;
////	}
////	int cur=0;
////	queue<P>que;
////	int emptyc=0;
////	for(int i=0;i<n;i++)
////	{
////			for(int j=0;j<m;j++)
////			{
////				if(f[i][j]=='.')
////				{
////					if(que.empty()) que.push(mp(i,j));
////					emptyc++;
////				}
////			}
////	}
////	
////	while(!que.empty())
////	{
////		P p=que.front(); que.pop();
////		if(ok[p.first][p.second]) continue;
////		ok[p.first][p.second]=true;
////		cur++;
////		if(cur==emptyc-k)
////		{	
////			for(int i=0;i<n;i++)
////			{
////				for(int j=0;j<m;j++)
////				{
////					if(!ok[i][j]) f[i][j]='X';
////				}
////			}
////			for(int i=0;i<n;i++) printf("%s\n",f[i]);
////			return 0;
////		}
////		int dx[4]={0,1,0,-1};
////		int dy[4]={1,0,-1,0};
////		for(int i=0;i<4;i++)
////		{
////				int nx=p.first+dx[i];
////				int ny=p.second+dy[i];
////				if(!(0<=nx && nx<n)) continue;
////				if(!(0<=ny && ny<m)) continue;
////				if(!ok[nx][ny] && f[nx][ny]=='.')
////				{
////					que.push(mp(nx,ny));
////				}
////		}
////	}
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef long long ll;
////typedef pair<ll,ll> P;
////typedef pair<P,int> P1;
////typedef pair<P,P> P2;
////
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////P bug[100005];
////ll abi[100005];
////ll mon[100005];
////P1 student[100005];
////int ret[100005];
////int main()
////{
////	int n,m;
////	ll s;
////	scanf("%d %d %lld",&n,&m,&s);
////	ll bugmax=-1LL;
////	ll abimax=-1LL;
////	for(int i=0;i<m;i++)
////	{
////		ll bugg;
////		scanf("%lld",&bugg);
////		bug[i]=mp(bugg,i);
////		bugmax=max(bugmax,bug[i].first);
////	}
////	for(int i=1;i<=n;i++)
////	{
////		scanf("%lld",&abi[i]);
////		abimax=max(abimax,abi[i]);
////	}
////	for(int i=1;i<=n;i++)
////	{
////		scanf("%lld",&mon[i]);
////		student[i-1]=mp(mp(abi[i],mon[i]),i);
////	}
////	if(bugmax>abimax)
////	{
////		puts("NO"); return 0;
////	}
////	sort(bug,bug+m,greater<P>());
////	sort(student,student+n,greater<P1>());
////	int lb=-1; int ub=100005;
////	while(ub-lb>1)
////	{
////		int mid=(lb+ub)>>1;
////		int cur=0;
////		int bugn=0;
////		priority_queue<P1,vector<P1>,greater<P1> >que;
////		while(!que.empty()) que.pop();
////		ll val=0LL;
////		while(bugn<m)
////		{
////			while(cur!=n && student[cur].first.first>=bug[bugn].first)
////			{
////				que.push(mp(mp(student[cur].first.second,student[cur].first.first),student[cur].second));
////				cur++;
////			}
////			val+=que.top().first.first; que.pop();
////			bugn+=mid;
////		}
////		if(val<=s) ub=mid;
////		else lb=mid;
////	}
////	puts("YES");
////		int mid=ub;
////		int cur=0;
////		int bugn=0;
////		priority_queue<P1,vector<P1>,greater<P1> >que;
////		while(!que.empty()) que.pop();
////		ll val=0LL;
////		while(bugn<m)
////		{
////			while(cur!=n && student[cur].first.first>=bug[bugn].first)
////			{
////				que.push(mp(mp(student[cur].first.second,student[cur].first.first),student[cur].second));
////				cur++;
////			}
////			for(int i=bugn;i<min(bugn+mid,m-1);i++)
////			{
////				ret[bug[i].second]=que.top().second;
////			}
////			que.pop();
////			bugn+=mid;
////		}
////		for(int i=0;i<m;i++)
////		{
////			printf("%d%c",ret[i],(i==m-1)?'\n':' ');
////		}
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int dp[21][21];
////int main()
////{
////	int n;
////	int s[105];
////	scanf("%d",&n);
////	for(int i=0;i<n;i++) scanf("%d",&s[i]);
////	sort(s,s+n,greater<int>());
////	int m;
////	scanf("%d",&m);
////	int act[25];
////	for(int i=0;i<m;i++)
////	{
////		string a; int b;
////		cin >> a >> b;
////		if(a=="p" && b==1) act[i]=1;
////		if(a=="p" && b==2) act[i]=2;
////		if(a=="b" && b==1) act[i]=3;
////		if(a=="b" && b==2) act[i]=4;
////	}
////	for(int i=0;i<21;i++)for(int j=0;j<21;j++)dp[i][j]=-INF;
////	dp[0][0]=0;
////	//
////		for(int j=0;j<m;j++)
////		{
////				for(int i=0;i<m;i++)
////				{
////						if(act[j]==1)
////						{
////							dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+s[i]);
////						}
////						else if(act[j]==2)
////						{
////							dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-s[i]);
////						}
////						else
////						{
////							dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
////							dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
////						}
////				}
////		}
////	int ret=-INF;
////	for(int i=0;i<21;i++) ret=max(ret,dp[i][m]);
////	printf("%d\n",ret);
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int main()
////{
////	int a,b;
////	cin >> a >> b;
////	int rem=a,ret=a;
////	while(rem>=b)
////	{
////			int x=rem/b;
////			int y=rem%b;
////			ret+=x;
////			rem=x+y;
////	}
////	cout << ret << endl;
////}
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////int main()
////{
////	int n;
////	int v[305];
////	scanf("%d",&n);
////	for(int i=0;i<n;i++) scanf("%d",&v[i]);
////	for(int i=0;i<n;i++)
////	{
////		while(v[i])
////		{
////			printf("P");
////			v[i]--;
////			if(!v[i]) break;
////			if(i-1>=0) printf("LR");
////			else printf("RL");
////		}
////		printf("R");
////	}
////}
//
//
//////Daily Lunch Special Tanoshii !!
////#include <cstdio>
////#include <cstring>
////#include <cstdlib>
////#include <cmath>
////#include <string>
////#include <algorithm>
////#include <vector>
////#include <queue>
////#include <stack>
////#include <functional>
////#include <iostream>
////#include <map>
////#include <set>
////using namespace std;
////typedef pair<int,int> P;
////typedef pair<int,P> P1;
////typedef pair<P,P> P2;
////typedef long long ll;
////#define pu push
////#define pb push_back
////#define mp make_pair
////#define eps 1e-7
////#define INF 2000000000
////#define s(x) scanf("%d",&x)
////#define rep(i,x) for(int i=0;i<x;i++)
////P v[300005];
////int ret[300005];
////int main()
////{
////	int n;
////	scanf("%d",&n);
////	for(int i=0;i<n;i++)
////	{
////		int vl; scanf("%d",&vl);
////		v[i]=mp(vl,i);
////	}
////	sort(v,v+n);
////	int prev=-1;
////	for(int i=0;i<n;i++)
////	{
////		if(prev>=v[i].first)
////		{
////			prev++;
////			ret[v[i].second]=prev;
////		}
////		else
////		{
////			prev=v[i].first;
////			ret[v[i].second]=prev;
////		}
////	}
////	for(int i=0;i<n;i++)
////	{
////		printf("%d%c",ret[i],i==n-1?'\n':' ');
////
////	}
////}
//
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int k,n,m;
	ll x;
	scanf("%d %lld %d %d",&k,&x,&n,&m);
	//0='A' 1='C' 2='B'
	for(int x1=0;x1<3;x1++)
	{
		for(int x2=0;x2<3;x2++)
		{
			if(n==1 && x1!=x2) continue;
			for(int y1=0;y1<3;y1++)
			{
				for(int y2=0;y2<3;y2++)
				{
					if(m==1 && y1!=y2) continue;
					ll a1=1LL,b1=0LL,add1=0LL;
					ll a2=0LL,b2=1LL,add2=0LL;
					for(int i=3;i<=k;i++)
					{
						ll a3=a1+a2;
						ll b3=b1+b2;
						ll add3=add1+add2;
						if(i==3)
						{
							if(x2==0 && y1==1) add3++;
						}
						else if(i%2==0)
						{
							if(y2==0 && x1==1) add3++;
						}
						else
						{
							if(y2==0 && y1==1) add3++;
						}
						a1=a2; b1=b2; add1=add2;
						a2=a3; b2=b3; add2=add3;
					}
					//cout << a2 << " " << b2 << " " << add2 <<endl;
					int nn=n,mm=m;
					if(x1!=0) nn--;
					if(x2!=1) nn--;
					if(y1!=0) mm--;
					if(y2!=1) mm--;
					char s[3]={'A','C','B'};
					int v=0,w=0;
					if(n==2 && x1==0 && x2==1) v=1;
					if(m==2 && y1==0 && y2==1) w=1;
					for(int i=v;i<=nn/2;i++)
					{
						for(int j=w;j<=mm/2;j++)
						{ 
							if(1LL*a2*i+1LL*b2*j+add2==x)
							{ 
								string a,b;
								a.resize(n);
								b.resize(m);
								int beg,en,cur=0;
								a[0]=s[x1];
								beg=x1!=0?1:0;
								a[n-1]=s[x2];
								en=x2==1?n-1:n-2;
								for(int ii=beg;ii<en && cur!=i;ii+=2)
								{
									a[ii]='A';
									a[ii+1]='C';
									cur++;
								}
								for(int ii=0;ii<n;ii++)
								{
									if(a[ii]!='A' && a[ii]!='C') a[ii]='B';
								}
								b[0]=s[y1];
								beg=y1!=0?1:0;
								b[m-1]=s[y2];
								en=y2==1?m-1:m-2;
								cur=0;
								for(int ii=beg;ii<en && cur!=j;ii+=2)
								{
									b[ii]='A';
									b[ii+1]='C';
									cur++;
								}
								for(int ii=0;ii<m;ii++)
								{
									if(b[ii]!='A' && b[ii]!='C') b[ii]='B';
								}
								cout << a << endl << b << endl; cin >> a;
								return 0;
							}
						}
					}

				}
			}
		}
	}
	puts("Happy new year!");
}