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
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int a[100005];
int vis[100005];
int main(){
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	MEM(vis);
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int cnt=0;
			int k=i;
			do{
				cnt++;
				k=a[k];
			//	printf("%d",k);
				vis[k]=1;
			}while(k!=i);
			v.pb(cnt);
		}
	}
	sort(v.begin(),v.end());
	int x=v.back();
	v.pop_back();
	if(v.empty())
	v.pb(x);
	else
	v.back()+=x; 
	LL sum=0;
	for(auto it=v.begin();it!=v.end();it++){
	//	printf("%I64d\n",*it);
		sum+=sqr((LL)*it);
	}
	printf("%I64d\n",sum);
	return 0;
}