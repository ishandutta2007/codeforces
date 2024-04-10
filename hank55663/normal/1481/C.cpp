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
void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100005],b[100005],c[100005];
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	for(int i = 0;i<n;i++)scanf("%d",&b[i]);
	map<int,queue<int> > mm;
	for(int i = 0;i<m;i++)scanf("%d",&c[i]),mm[c[i]].push(i);
	int ok=0;
	for(int i= 0;i<n;i++){
		if(b[i]==c[m-1])ok=1;
	}
	int ans[100005];
	fill(ans,ans+m+1,0);
	for(int i = 0;i<n;i++){
		if(a[i]!=b[i]){
			if(mm[b[i]].size()){
				ans[mm[b[i]].front()]=i+1;
				mm[b[i]].pop();
			}
			else ok=0;
		}
	}
	if(ans[m-1]){
		for(int i = 0;i<m;i++){
			if(!ans[i])ans[i]=ans[m-1];
		}
	}
	else{
		for(int i = 0;i<n;i++){
			if(b[i]==c[m-1]){
				for(auto &it:mm){
					while(!it.y.empty()){
						ans[it.y.front()]=i+1;
						it.y.pop();
					}
				}
				break;
			}
		}
	}
	if(ok){
		printf("YES\n");
		for(int i = 0;i<m;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	else{
		printf("NO\n");
	}
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/