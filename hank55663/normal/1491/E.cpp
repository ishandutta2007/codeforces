#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
vector<int> dfs(int x,int f){
	vector<int> tmp;
	for(auto it:v[x]){
		if(it!=f){
			auto v2=dfs(it,x);
			for(auto it2:v2)tmp.pb(it2);
		}
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	int now=1;
	if(tmp.size()&&tmp.back()==1){
		tmp.pop_back();
		now=2;
	}
	//for(auto it:tmp)printf("%d ",it);
	//printf(" %d %d\n",now,x);
	for(int i = 0;i+2<tmp.size();i++){
		if(tmp[i]==tmp[i+2]){
			printf("NO\n");
			exit(0);
		}
	}
	while(tmp.size()&&abs(tmp.back()-now)==1){
		now=max(now,tmp.back())+1;
		tmp.pop_back();
	}
	if(tmp.size()&&tmp.back()<now){
		printf("NO\n");
			exit(0);
	}
	tmp.pb(now);

	return tmp;
}
bool solve(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	auto v=dfs(1,0);
	if(v.size()!=1)printf("NO\n");
	else printf("YES\n");
}
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
   // scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}