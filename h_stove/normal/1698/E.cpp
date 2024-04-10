//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){
	for (auto &x:a) cin>>x;
	int n=a.size(),i;
	vector<int> pos(n,-1);
	for (i=0;i<n;i++) if (a[i]!=-1) pos[a[i]-1]=i;
	a=pos;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
const ui p=998244353;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n>>m;m=min(m,n-1);
		vector<int> a(n),b(n),pos(n),app(n,-1);
		cin>>a>>b;
		for (i=0;i<n;i++) pos[a[i]]=i;
		for (int &x:b) x=x==-1?-1:pos[x];
		for (i=0;i<n;i++) if (b[i]!=-1) app[b[i]]=i;
		for (i=0;i<n;i++) if (b[i]>i+m) break;
		if (i<n) {cout<<"0\n";continue;}
		ui r=1,cur=0;
		for (i=n-1;i>=n-m-1;i--) cur+=b[i]==-1;
		for (i=n-1;i>=0;i--)
		{
			if (app[i]==-1)
			{
				r=(ll)r*cur%p;
				--cur;
			}
			if (i-(m+1)>=0) cur+=b[i-(m+1)]==-1;
		}
		cout<<r<<'\n';
		cout.flush();
	}
}