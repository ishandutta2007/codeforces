#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

vector<int> operator + (vector<int>a,vector<int>b)
{
	for (auto x:b)a.pb(x);
	return a;
}

int query(vector<int>v)
{
	cout<<"? "<<v.size();
	for (auto x:v)cout<<' '<<x;
	cout<<endl;
	string s;cin>>s;
	if (s=="YES")return 1;
	else return 0;
}

void solve(vector<int>v)
{
	if (v.size()<=2)
	{
		cout<<"! "<<v[0]<<endl;
		string s;cin>>s;
		if (s==":(")
			cout<<"! "<<v[1]<<endl,cin>>s;
		assert(s==":)");
		return;
	}
	int n=v.size(),n1=n/3,n2=n/3,n3=n/3;
	if (n%3==1)n3++;
	else if (n%3==2)n2++,n3++;
	vector<int>v1(n1),v2(n2),v3(n3);
	for (int i=0;i<n1;i++)v1[i]=v[i];
	for (int i=0;i<n2;i++)v2[i]=v[i+n1];
	for (int i=0;i<n3;i++)v3[i]=v[i+n1+n2];
	int f=query(v1);
	if (f)
	{
		int f2=query(v2);
		if (f2==0)solve(v1+v3);
		else solve(v1+v2);
	}
	else
	{
		int f2=query(v2+v3);
		if (f2)solve(v2+v3);
		else
		{
			int f3=query(v1+v2);
			if (f3)solve(v1+v2);
			else solve(v1+v3);
		}
	}
}

signed main()
{
	int n=read();
	vector<int>v;
	for (int i=1;i<=n;i++)v.pb(i);
	solve(v);
	return 0;
}