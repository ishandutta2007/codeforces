#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> vi;
typedef pair<int,int> pa;
const int N=1e5+11;
struct E{
	int x,y,i;
	ld w;
	void scan(){
		scanf("%d%d%lf",&x,&y,&w);
		if(x>y)swap(x,y);
	}
	bool operator<(const E&t)const{
		return w<t.w;
	}
} e[N],s[N];
int f[N];
//#define fo sfsfsadghqoae
int fo(int i){return f[i]==i?i:f[i]=fo(f[i]);}
int n,m,K,v[N],g;
int main(){
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
#endif
	cin>>n>>m>>K;
	int x,y,d=0;
	rep(i,1,m)
		e[i].scan(),e[i].i=i,d+=e[i].x==1;
	if((n>1&&!K)||d<K||m<n-1)return puts("-1"),0;
	ld l=-1e9,r=1e9;
	while(1){
		ld M=(l+r)/2;
		rep(i,1,m){
			s[i]=e[i];
			if(s[i].x==1)s[i].w+=M;
		}
		sort(s+1,s+m+1);
		rep(i,1,n)f[i]=i;
		g=0;
		d=0;
		rep(i,1,m){
			x=fo(s[i].x);
			y=fo(s[i].y);
			if(x!=y){
				v[++g]=s[i].i;
				f[x]=y;
				d+=s[i].x==1;
			}
			//printf("%f%c",s[i].w," \n"[i==m]);
		}
		if(d==K)break;
		//cerr<<d<<endl;
		if(d<K)r=M;
		else l=M;
	}
	if(g<n-1)return puts("-1"),0;
	printf("%d\n",g);
	rep(i,1,g)printf("%d%c",v[i]," \n"[i==g]);
}