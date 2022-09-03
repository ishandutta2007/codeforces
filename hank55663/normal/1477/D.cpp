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
vector<int> v[500005];
int ans1[500005];
int ans2[500005];
vector<pair<set<int>,set<int> > > vv;
int loc[500005];
int f[500005];
int Find(int x){
	if(f[x]==x)return x;
	return f[x]=Find(f[x]);
}
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++)v[i].clear();
	vv.clear();
	for(int i = 0;i<m;i++){
		int x=rand()%n+1,y=rand()%n+1;
		scanf("%d %d",&x,&y);
		//while(y==x)y=rand()%n+1;
	///	printf("%d %d\n",x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 1;i<=n;i++)f[i]=i;
	fill(loc,loc+n+1,-1);
	int now=n;
	for(int i = 1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		if(v[i].size()==n-1){
			ans1[i]=ans2[i]=now--;
		}
	}
	for(int i = 1;i<=n;i++){
		if(v[i].size()!=n-1&&loc[i]==-1){
			v[i].pb(1e9);
			int now=1;
			for(int j  =0;j<v[i].size();j++){
				if(now==i)now++;
				if(v[i][j]!=now){
					//printf("%d %d??\n",i,now);
					if(loc[now]!=-1){
						if(vv[loc[now]].x.find(now)!=vv[loc[now]].x.end()){
							if(vv[loc[now]].x.size()==1){
								vv[loc[now]].y.insert(i);
								loc[i]=loc[now];
							}
							else{
								set<int> s1,s2;
								s1.insert(i);
								s2.insert(now);
								vv.pb(mp(s1,s2));
								vv[loc[now]].x.erase(now);
								//vv.pb(mp(s1,s2));
								loc[i]=loc[now]=vv.size()-1;
							}
						}
						else{
							if(vv[loc[now]].y.size()==1){
								vv[loc[now]].x.insert(i);
								loc[i]=loc[now];
							}
							else{
								set<int> s1,s2;
								s1.insert(i);
								s2.insert(now);
								vv.pb(mp(s1,s2));
								vv[loc[now]].y.erase(now);
								//vv.pb(mp(s1,s2));
								loc[i]=loc[now]=vv.size()-1;
							}
						}
						break;
					}
					else{
						set<int> s1,s2;
						s1.insert(i);
						s2.insert(now);
						vv.pb(mp(s1,s2));
						loc[i]=loc[now]=vv.size()-1;
						
						break;
					}
				}
				now++;
			}
			v[i].pop_back();
			
			//printf("%d %d\n",i,loc[i]);
		}
	}
	
	for(int i = 1;i<=n;i++){
		if(v[i].size()!=n-1)
		for(auto it:v[i]){
			if(loc[i]==loc[it]){
				f[Find(i)]=Find(it);
			}
		}
	}
	//printf("?\n");
	for(auto it:vv){
		//	printf("?\n");
		vector<int> v1,v2;
		for(auto it2:it.x){
		//	printf("%d ",it2);
			v1.pb(it2);
		}
		//printf("\n");
		for(auto it2:it.y){
		//	printf("%d ",it2);
			v2.pb(it2);
			//else v2.pb(it2);
		}
	//	printf("@\n");
		//sort(v1.begin(),v1.end());
		//sort(v2.begin(),v2.end());
			//printf("%d\n",now);
		int l=now-it.x.size()-it.y.size()+1;
		for(auto it:v1)ans1[it]=l++;
		for(auto it:v2)ans1[it]=l++;
		l=now-it.x.size()-it.y.size()+1;
		for(auto it:v2)ans2[it]=l++;
		for(auto it:v1)ans2[it]=l++;
		now=now-it.x.size()-it.y.size();
	
	}
	for(int i = 1;i<=n;i++)printf("%d ",ans1[i]);
	printf("\n");
	for(int i = 1;i<=n;i++)printf("%d ",ans2[i]);
	printf("\n");
	for(int i = 1;i<=n;i++){
		if(ans1[i]==ans2[i]&&v[i].size()!=n-1){
			assert(0);
		}
		for(auto it:v[i]){
			assert((ans1[it]<ans1[i])==(ans2[it]<ans2[i]));
		}
	}
	
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/