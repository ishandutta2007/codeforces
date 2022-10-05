#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
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
int n;
bool judge(int x,int y){
	cout<<"1 "<<x-1<<' '<<y-1<<endl;
	cin>>x; if(x==-1)exit(0); return x;
}
bool ask(int x,vector<int>y){
	if(!y.size()) return 0;
	cout<<2<<' '<<x-1<<' '<<y.size();
	for(auto z:y)cout<<' '<<z-1; cout<<endl;
	int res; cin>>res; return res;
}
int p[105];
bool a[105][105];
vector<int> pref(int x){
	vector<int>o;
	For(i,1,x)o.pb(p[i]);
	return o;
}
void work()
{
	cin>>n;
	For(i,1,n)p[i]=i;
	stable_sort(p+1,p+n+1,judge);
	memset(a,1,sizeof a);
	int pos=n-1;
	Rep(i,n,1){
		if(pos==i){
			For(j,1,i)
				For(k,i+1,n)
					a[p[k]][p[j]]=0;
			--pos;
		}
		while(ask(p[i],pref(pos))) --pos;
	}
	puts("3");
	For(i,1,n){
		For(j,1,n) printf("%d",a[i][j]);
		printf("\n");
	}
	fflush(stdout);
	int res; cin>>res;
	if(res==-1)exit(-1);
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}