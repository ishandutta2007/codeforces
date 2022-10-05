#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 200005
#define inf 0x3f3f3f3f

int n;
string s1,s2,s3;
int ca[2],cb[2];
string work(string a,string b){
	string c;
	For(i,0,1)ca[i]=cb[i]=0;
	For(i,0,2*n-1)ca[a[i]-'0']++,cb[b[i]-'0']++;
	bool ok=((ca[0]>=n)&&(cb[0]>=n));
	ok|=((ca[1]>=n)&&(cb[1]>=n));
//	cout<<ca[0]<<" "<<cb[0]<<" "<<ca[1]<<' '<<cb[1]<<endl;
	if(!ok)return a+b;
	int id; if(ca[0]>=n&&cb[0]>=n)id=0;else id=1;
	//cout<<a<<" "<<b<<" id "<<id<<endl; 
	int mx=max(ca[id],cb[id]);
	int p=0,q=0;
	while(p<2*n&&q<2*n){
		if(a[p]==b[q]){
			c+=a[p],p++,q++; 
			continue;
		}
		if(a[p]-'0'==id)c+=b[q],++q;
		else c+=a[p],++p;
	//	cout<<p<<' '<<q<<endl;
	}
	while(p<2*n)c+=a[p],++p;
	while(q<2*n)c+=b[q],++q;
//	for(auto xx:c)cout<<xx<<' ';puts("");
	return c;
}
void work()
{
	n=read(),cin>>s1>>s2>>s3;
	string t1=work(s1,s2); 
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	t1=work(s2,s3); //puts("qaq");
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	t1=work(s1,s3); //puts("qaq");
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	t1=work(s3,s1);
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	t1=work(s2,s1); 
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	t1=work(s3,s2); 
	if(t1.size()<=3*n){cout<<t1<<endl;return;}
	exit(233);
}
// cnt[i] = (2^(i-1))
signed main()
{
//	freopen("data","r",stdin);
//	cout<<(1ll<<62)<<endl;
//	cout<<1000000000000000000ll<<endl;
	int T=read();
	while(T--)work();
	return 0;
}