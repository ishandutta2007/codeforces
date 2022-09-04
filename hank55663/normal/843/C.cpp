#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
vector<int> v[200005];
int Size[200005];
int Min;
vector<int> center;
int n;
void find_center(int a,int f){
	int Max=0,sum=1;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			find_center(*it,a);
			sum+=Size[*it];
			Max=max(Max,Size[*it]); 
		}
	} 
	Max=max(Max,n-sum);
	Size[a]=sum;
//	printf("%d %d %d\n",a,Size[a],Max);
	if(Max<Min){
		Min=Max;
		center.clear();
	}
	if(Max==Min){
		center.pb(a);
	} 
}
vector<pair<pii,int> > ans;
pii dfs(int a,int f){
	//printf("a:%d\n",a);
	vector<int> vi;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			pii p=dfs(*it,a);
		//	printf("%d %d %d\n",a,*it,p.x);
			*it=p.x;
			vi.pb(p.y);
		}		
	}
	//printf("%d",a);
	int fa=f;
	int cnt=0;
	for(int i=0;i-cnt<vi.size();i++){
		//printf("%d: %d",a,v[a][i]);
		if(v[a][i]!=f){
			ans.pb(mp(mp(fa,a),vi[i-cnt]));
			v[vi[i-cnt]].pb(fa);
			if(fa!=f)
			for(vector<int>::iterator it=v[fa].begin();it!=v[fa].end();it++){
				if(*it==a){
					*it=vi[i-cnt];
				}
			}
			fa=v[a][i];
		}
		else
		cnt++;
	}
	//printf("%d",a);
	v[a].clear();
	v[a].pb(fa);
	//printf("%d %d\n",a,fa);
	if(vi.empty())
	vi.pb(a);
	return mp(vi[0],a);
}
int dfs2(int a,int f){
//	printf("%d %d\n",a,f);
//	system("PAUSE");
	int ret=a;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			int p=dfs2(*it,a);
			ans.pb(mp(mp(a,*it),p));
			ret=p;
		}
	}
	return ret;
}
int main(){
	Min=1e9; 
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	find_center(1,0);
	if(center.size()==1){
		for(vector<int>::iterator it=v[center[0]].begin();it!=v[center[0]].end();it++){
		//	printf("%d ",*it);
			*it=dfs(*it,center[0]).x;
		//	printf("%d",*it);
			int p=dfs2(*it,center[0]);
			ans.pb(mp(mp(center[0],*it),p));
		//	printf("ok\n");
		}
	}
	else{
		for(int i=0;i<2;i++){
			for(vector<int>::iterator it=v[center[i]].begin();it!=v[center[i]].end();it++){
				if(*it==center[i^1])
				continue;
				*it=dfs(*it,center[i]).x;
				int p=dfs2(*it,center[i]);
				ans.pb(mp(mp(center[i],*it),p));
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d %d\n",ans[i].x.x,ans[i].x.y,ans[i].y);
	}
}