#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
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
#define next Next
using namespace std;
typedef long long LL;
vector<int> v[200005];
int s,t,h;
pii dfs(int a,int f){
	pii heigh1=mp(0,a),heigh2=mp(0,0);
	for(auto &it:v[a]){
		if(it!=f){
			pii p=dfs(it,a);
			if(p>heigh1){
				heigh2=heigh1;
				heigh1=p;
			}
			else if(p>heigh2){
				heigh2=p;
			}
		}
	}
	//printf("%d %d %d %d %d\n",a,heigh1.x,heigh1.y,heigh2.x,heigh2.y);
	if(h<heigh1.x+heigh2.x){
		s=heigh1.y;
		t=heigh2.y;
		h=heigh1.x+heigh2.x;
	}
	heigh1.x++;
	return heigh1;
}
vector<int> path;
bool dfs2(int a,int f,int t){
	path.pb(a);
	if(a==t)
	return true;
	for(auto &it:v[a]){
		if(it!=f){
			if(dfs2(it,a,t)){
				return true;
			}
		}
	}
	path.pop_back();
	return false;
}
vector<pii> ans;
LL res; 
void dfs3(int a,int f,int from,int sum){
	for(auto &it:v[a]){
		if(it!=f){
			dfs3(it,a,from,sum+1);
		}
	}
	res+=sum;
	ans.pb(mp(from,a));
}
int main(){
	int n;
	h=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	} 
	dfs(1,0);
	path.clear();
//	printf("%d %d\n",s,t);
	path.pb(0);
	dfs2(s,0,t);
	path.pb(0);
	res=0;
	h++;
	for(int i=1;i<path.size()-1;i++){
		for(auto &it:v[path[i]]){
			if(it!=path[i-1]&&it!=path[i+1]){
				if(h-i>i-1){
					dfs3(it,path[i],path[h],h-i+1);
				}
				else{
					dfs3(it,path[i],path[1],i); 
				}
			}
		}
	}
	for(int i=1;i<h;i++){
		res+=h-i;
	//	printf("%d %d\n",path[h],path[i]);
		ans.pb(mp(path[h],path[i]));
	}
	printf("%I64d\n",res);
	for(auto &it:ans){
		printf("%d %d %d\n",it.x,it.y,it.y);
	}
}