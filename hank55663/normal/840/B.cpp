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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
using namespace std;
int need[300005];
vector<pii> v[300005];
vector<int> ans;
int d[300005];
int visit[300005];
int last;
int dfs1(int n){
	//printf("%d %d\n",n,last);
	visit[n]=1;
	int sum=0;
	for(vector<pii>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[it->x])
		sum+=dfs1(it->x); 
	}
	if(d[n]==-1)
	last=n;//printf("?");
	if(d[n]==1)
	sum++,need[n]=1;
	return sum;
}
vector<int>* dfs(int n){
	visit[n]=1;
	vector<int> *temp=new vector<int>;
	for(vector<pii>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[it->x]){
			if(temp->empty()){
				temp=dfs(it->x);
				if(!temp->empty())
				temp->pb(it->y);
			}
			else{
				vector<int>* temp2=dfs(it->x);
				if(!temp2->empty()){
					temp2->pb(it->y);
					for(int i=1;i<temp->size();i++)
					ans.pb((*temp)[i]);
					for(int i=1;i<temp2->size();i++)
					ans.pb((*temp2)[i]);
					temp->clear();
				}
			}
		}
	}
	if(need[n]){
		if(temp->empty()){
			temp->pb(n);
		}
		else{
			for(int i=1;i<temp->size();i++)
			ans.pb((*temp)[i]);
			temp->clear();
		}
	}
	return temp;
} 
int main(){

	int n,m;
	scanf("%d %d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(mp(b,i));
		v[b].pb(mp(a,i));
	}
	MEM(visit);
	MEM(need);
	int ok=1;
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			last=-1;
			if(dfs1(i)%2==1){
				//printf("%d\n",last);
				if(last==-1)
				ok=0;
				else
				need[last]=1;	
			}
		}
	}
	if(!ok)
	{
		printf("-1");
	}
	else{
		MEM(visit);
		for(int i=1;i<=n;i++)
		if(!visit[i])
		dfs(i);
		printf("%d\n",ans.size());
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	}
}
/*
1 2 2 3 3
7 5 4 3 3
*/