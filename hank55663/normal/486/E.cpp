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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
bool cmp(const vector<pll> &v,const vector<pll> &v2){
	return v.back()<v2.back();
}
int main(){
	int ans[100005];
	MEM(ans);
		int n;
		scanf("%d",&n);
		vector<vector<pll> > v;
		for(int i=0;i<n;i++){
			LL a;
			scanf("%lld",&a);
			if(v.empty()||v.back().back().x<a){
				vector<pll> vv;
				vv.pb(mp(a,i));
				v.pb(vv);
			} 
			else{
				vector<pll> vv;
			//	printf("!");
				vv.pb(mp(a,0));
				auto it=lower_bound(v.begin(),v.end(),vv,cmp);
			//	printf("%d %d\n",it->back().y,i);
				it->pb(mp(a,i));
			}//printf("?");
		}
		vector<pll> temp=v.back();
		if(temp.size()==1)
		ans[temp.back().y]=3;
		else
		for(auto it:temp)
		ans[it.y]=2;
		vector<pll> temp2;
		v.pop_back();
	//	reverse(temp.begin(),temp.end());
		while(!v.empty()){
			temp2.clear();
			vector<pll> vv=v.back();
			v.pop_back();
			while(!temp.empty()&&!vv.empty()){
				while(!vv.empty()&&vv.back().y>temp.back().y)vv.pop_back();
				while(!vv.empty()&&vv.back().x<temp.back().x&&vv.back().y<temp.back().y){
					temp2.pb(vv.back());
					vv.pop_back();
				}
				temp.pop_back();
			}
			swap(temp,temp2);
			if(temp.size()==1)
			ans[temp.back().y]=3;
			else
			for(auto it:temp)
			ans[it.y]=2;
			reverse(temp.begin(),temp.end());
		}
		for(int i=0;i<n;i++){
			if(ans[i]==0)
			printf("1");
			else
			printf("%d",ans[i]);
		}
		printf("\n");
}
/*
4 5 6,3
1 2 3,6
*/