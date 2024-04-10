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
	int n,m;
	scanf("%d %d",&n,&m);
	map<int,int> s[100005];
	for(int i=0;i<=n;i++)
	s[i][-1]=0;
	int ans=0;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		auto it=s[a].lower_bound(c);
		it--;
		s[b][c]=max(s[b][c],it->y+1);
		ans=max(ans,s[b][c]);
		while(1){
			auto it =s[b].find(c);
			it++;
			if(it==s[b].end())
			break;
			if(it->y<=s[b][c])
			s[b].erase(it);
			else
			break;
		}
		it=s[b].find(c);
		it--;
		if(it->y>=s[b][c]){
			s[b].erase(c);
		}
	}
	printf("%d\n",ans);
}