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
pii p[200005];
bool solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		p[i]=mp(x,i+1);
	}
	sort(p,p+n);
	set<int> ok;
	LL pre=0;
	for(int i = 0;i<n;i++){
		if(pre<p[i].x){
			ok.clear();
		}
		pre+=p[i].x;
		ok.insert(p[i].x);
	}
	vector<int> ans;
	for(int i =0;i<n;i++){
		if(ok.find(p[i].x)!=ok.end())ans.pb(p[i].y);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it:ans){
		printf("%d ",it);
	}
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}