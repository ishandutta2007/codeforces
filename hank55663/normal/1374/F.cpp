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
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[505];
		for(int i = 0;i<n;i++){
			scanf("%d",&a[i]);
		}
		vector<int> ans;
		for(int i = 0;i<n-2;i++){
			int Min=1e9,ansi;
			for(int j = i;j<n;j++){
				if(a[j]<Min){
					Min=a[j];
					ansi=j;
				}
			}
		//	printf("%d\n",ansi);
			while(ansi>=i+2){
				ans.pb(ansi-2);
				swap(a[ansi],a[ansi-1]);
				swap(a[ansi-1],a[ansi-2]);
				ansi-=2;
			}
			if(ansi!=i){
				ans.pb(i);
				ans.pb(i);
				swap(a[ansi],a[ansi-1]);
				swap(a[ansi],a[ansi+1]);
			}
			
			/*for(int j = 0;j<n;j++){
				printf("%d ",a[j]);
			}
			printf("\n");*/
		}
		if(a[n-2]>a[n-1]){
			if(a[n-1]==a[n-3]){
				ans.pb(n-3);
				printf("%d\n",ans.size());
				for(auto it:ans){
					printf("%d " ,it+1);
				}
				printf("\n");
			}
			else{
				int ok=0;
				for(int j  =0;j<n;j++){
					if(a[j]==a[j+1]){
						for(int k=n-3;k>=j;k--){
							ans.pb(k);
						}	
						printf("%d\n",ans.size());
						for(auto it:ans){
							printf("%d " ,it+1);
						}
						printf("\n");
						ok=1;
						break;
					}
				}
				if(!ok)
				printf("-1\n");
			}
		}
		else{
			printf("%d\n",ans.size());
			for(auto it:ans){
				printf("%d ",it+1);
			}
			printf("\n");
		}
	}
	return 0;
}