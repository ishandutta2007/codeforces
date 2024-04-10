#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	int b[200005];
	int ans[200005];
	set<int> s;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
		if(a[i]!=0)
			ans[a[i]]=0;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]!=0)
			ans[b[i]]=i;
	}
	int Max=0;
	for(int i = 1;i<=n;i++){
		if(b[i]==1){
			Max=1;
		}
		else if(Max&&b[i]==b[i-1]+1){
			Max++;
		}
		else{
			Max=0;
		}
	}
	int res=0;
	while(Max!=n){
		if(s.find(Max+1)!=s.end()){
			res++;
			Max++;
			s.insert(b[res]);
		}
		else{
			break;
		}
	}
	if(Max==n){
		printf("%d\n",res);
	}
	else{
		res=0;
		for(int i = 1;i<=n;i++){
			//printf("%d\n",ans[i]);
			res=max(res,ans[i]);
			res++;
		}
		printf("%d\n",res);
	}
}