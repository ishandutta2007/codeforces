#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	pii p[100005];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	if(n<5){
		printf("YES\n");
		return 0;
	}
	sort(p,p+n);
	map<pii,int> m;
	for(int i=1;i<n;i++){
		int a=p[i].x-p[0].x;
		int b=p[i].y-p[0].y;
		int gcd=__gcd(a,b);
		m[mp(a/gcd,b/gcd)]++;
	}
	int cnt=0;
	pii pp;
	for(auto it:m){
		if(it.y!=1){
			cnt++;
			pp=it.x;
		}
	}
	//printf("?");
	if(m.size()<=2){
		printf("YES\n");
	}
	else if(cnt>1){
		printf("NO\n");
	}
	else if(cnt==1){
		int ok[100005];
		MEM(ok);
		for(int i=1;i<n;i++){
			int a=p[i].x-p[0].x;
			int b=p[i].y-p[0].y;
			int gcd=__gcd(a,b);
			if(mp(a/gcd,b/gcd)==pp){
				ok[i]=1;
			}
		}
		pii hi;
		int i;
		for(i=1;i<n;i++)
			if(ok[i]==0){
				hi=p[i];
				break;
			}
		set<pii> s;
		for(i++;i<n;i++){
			if(!ok[i]){
				int a=p[i].x-hi.x;
				int b=p[i].y-hi.y;
				int gcd=__gcd(a,b);
				s.insert(mp(a/gcd,b/gcd));
			}
		}
		if(s.size()>1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	else{
		map<pii,int> hi;
		for(int i=2;i<n;i++){
			int a=p[i].x-p[1].x;
			int b=p[i].y-p[1].y;
			int gcd=__gcd(a,b);
			hi[mp(a/gcd,b/gcd)]++;
		}
		for(auto it:hi){
			if(it.y>=n-3){
				printf("YES\n");
				return 0;
			}
		}
		set<pii> hii;
		for(int i=3;i<n;i++){
			int a=p[i].x-p[2].x;
			int b=p[i].y-p[2].y;
			int gcd=__gcd(a,b);
			hii.insert(mp(a/gcd,b/gcd));
		}
		if(hii.size()>1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
}