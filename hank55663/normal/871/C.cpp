#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int f[100005];
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
bool cmp(pair<pii,int> &x,pair<pii,int> &y){
	return x.x.y<y.x.y;
}
vector<pii> v[100005];
int mod= 1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int inv[100005];
int main(){
	for(int i=1;i<100005;i++){
		inv[i]=f_pow(i,mod-2);
	}
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	f[i]=i;
	pair<pii,int> p[100005];
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i].x=mp(x,y); 
		p[i].y=i;
	}
	sort(p,p+n);
	for(int i=1;i<n;i++){
		if(p[i].x.x==p[i-1].x.x){
			f[Find(p[i].y)]=Find(p[i-1].y);
		}
	}
	sort(p,p+n,cmp);
	for(int i=1;i<n;i++){
		if(p[i].x.y==p[i-1].x.y){
			f[Find(p[i].y)]=Find(p[i-1].y);
		}
	}
	for(int i=0;i<n;i++){
		v[Find(p[i].y)].pb(p[i].x);
	}
	LL sum=1;
	for(int i=0;i<n;i++){
		set<int> s;
		for(auto it=v[i].begin();it!=v[i].end();it++){
			s.insert(it->x<<1);
			s.insert((it->y<<1)+1);
		}
		LL tot=1,last=1;
		for(int j=1;j<=v[i].size();j++){
			last=last*inv[j]%mod*(s.size()-j+1)%mod;
			tot+=last;
			tot%=mod;
		}
		sum*=tot;
		sum%=mod;
	//	printf("%I64d\n",sum);
	}
	printf("%I64d\n",sum);
	return 0;
}