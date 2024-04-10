#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
int a[5000000];
int f[5000000];
int num[5000000];
int hi[5000000];
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	MEM(hi);
	MEM(num);
	vector<int> v[30];
	vector<int> rev;
	for(int i=1;i<=m;i++){
		f[i]=i;
		int a;
		scanf("%d",&a);
		num[a]=i;
		hi[(1<<n)-1-a]=i;
	}
	for(int i=0;i<(1<<n);i++){
		int k=i;
		int sum=0;
		while(k){
			sum+=(k&1);
			k>>=1;
		}
		v[sum].pb(i);
	}
	for(int i=1;i<=n;i++){
		for(auto it:v[i]){
			for(int j=0;j<n;j++){
				if((it&(1<<j))&&num[it-(1<<j)]){
					num[it]=num[it-(1<<j)];
				}
			}
		}
	}
	int ans=m;
	for(int i=n;i>=0;i--){
		for(auto it:v[i]){
			if(hi[it]){
			//	printf("%d %d",it,hi[it]);
				for(int j=0;j<n;j++){
					if((it&(1<<j))&&num[it-(1<<j)]){
					//	printf(" %d %d",it-(1<<j),hi[it-(1<<j)]);
						if(hi[it-(1<<j)]==0)
						hi[it-(1<<j)]=hi[it];
						else{
							int fx=Find(hi[it-(1<<j)]);
							int fy=Find(hi[it]);
							//printf("%d %d\n",fx,fy);
							if(fx!=fy){
								f[fx]=fy;
								ans--;
								hi[it-(1<<j)]=fy;
							}
						}
					}
				}
			//	printf("\n");
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		if(num[i]&&hi[i]){
			int fx=Find(num[i]);
			int fy=Find(hi[i]);
			if(fx!=fy){
				f[fx]=fy;
				ans--;
			}
		}
	}
	printf("%d\n",ans);
}