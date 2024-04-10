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
int a[1000005];
int vis[1000005];
int ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int k=i;
			int sum=0;
			do{
				vis[k]=1;
				k=a[k];
				sum++;
			}while(k!=i);
			ans+=sum-1;
		}
	}
	//printf("%d\n",ans);
	int a=n*7+1,b=3*n;
	if((a-ans)>=0&&(a-ans)%2==0)
	printf("Um_nik\n");
	else
	printf("Petr\n");
}