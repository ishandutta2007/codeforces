#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
int use[2000005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){	
		int n;
		scanf("%d",&n);
		int a[105];
		MEM(use);
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		int ok=1;
		for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
		ok=0;
		if(!ok){
			printf("NO\n");
			continue;
		}
		vector<int> v;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				v.pb(a[j]-a[i]);
		vector<int> ans;
		for(int i=1;i<=1e6;i++){
			if(!use[i])
			{
				ans.pb(i);
				for(int j=0;j<v.size();j++)
				if(i+v[j]<2e6)
				use[i+v[j]]=1;
				if(ans.size()==n)
				break;
			}
		}
		printf("YES\n");
		for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
		printf("\n");
		
	}
}