#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[1005];
int Find(){
	for(int i = 0;;i++){
		if(!cnt[i])return i;
	}
}
int main() {
	int t;
	scanf("%d",&t);
	int a[1005];
	vector<int> v[1005];

	while(t--){
		int n=rand()%998+3;
		scanf("%d",&n);
	//	printf("%d\n",n);
	//	int r=rand()%(n)+1;
		for(int i = 0;i<=n;i++)cnt[i]=0;
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		//	a[i]=rand()%r;
		//	printf("%d ",a[i]);
			cnt[a[i]]++;
		//	v[a[i]].pb(i);
		}
		//printf("\n");
		vector<int> ans;
		for(int i = 0;i<n;i++){
			int x=Find();
			if(x==n){
				for(int j =0;j<n;j++){
					if(a[j]!=j){
						ans.pb(j);
						cnt[a[j]]--;
						cnt[x]++;
						a[j]=x;
						x=Find();
						break;
					}
				}
			}
			if(x==n)break;
			ans.pb(x);
			cnt[a[x]]--;
			cnt[x]++;
			a[x]=x;
		}
		//printf("%d\n",ans.size());
		//for(int i = 0;i<n;i++){
		//	printf("%d ",a[i]);
			
		//}
		//printf("\n");
		for(int i = 0;i<n-1;i++){
		//	printf("%d ",a[i]);
		assert(a[i]<a[i+1])	;
		}
		printf("%d\n",ans.size());
		assert(ans.size()<=2*n);
		//printf("%d\n",ans.size());
		for(auto it:ans){
			printf("%d ",it+1);
		}
		printf("\n");
	}
	return 0;
}