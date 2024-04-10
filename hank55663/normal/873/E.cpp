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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
#define N 300005
int dp[3005][3005];
pii a[5005];
int DP(int l,int r){
	if(l==r){
		return a[l-1].x-a[l].x;
	}
	if(dp[l][r]!=-1)
	return dp[l][r];
	return dp[l][r]=max(DP(l,r-1),a[r-1].x-a[r].x);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].x);
		a[i].y=i;
	}
	sort(a,a+n);
	reverse(a,a+n);
	MEMS(dp);
	int l,r,Max1=-1,Max2=-1,Max3=-1;
	for(int i=1;i<=n/2;i++)
		for(int j=i+(i+1)/2;j<n&&j<=i+i*2;j++){
		//	printf("%d %d %d %d",max((i+1)/2,(j-i+1)/2),min(i*2,(j-i)*2),j+max((i+1)/2,(j-i+1)/2),n);
			if(max((i+1)/2,(j-i+1)/2)<min(i*2,(j-i)*2)&&j+max((i+1)/2,(j-i+1)/2)<=n){
				if(a[i-1].x-a[i].x>Max1){
					Max1=a[i-1].x-a[i].x;
					Max2=a[j-1].x-a[j].x;
					Max3=DP(j+max((i+1)/2,(j-i+1)/2),j+min(i*2,(j-i)*2));
					l=i,r=j;
		//			printf("%d %d\n",l,r);
				}
				else if(a[i-1].x-a[i].x==Max1){
					if(a[j-1].x-a[j].x>Max2){
						Max2=a[j-1].x-a[j].x;
						Max3=DP(j+max((i+1)/2,(j-i+1)/2),j+min(i*2,(j-i)*2));
						l=i,r=j;
					}
					else if(a[j-1].x-a[j].x==Max2){
						if(DP(j+max((i+1)/2,(j-i+1)/2),j+min(i*2,(j-i)*2))>Max3){
							Max3=DP(j+max((i+1)/2,(j-i+1)/2),j+min(i*2,(j-i)*2));
							l=i,r=j;
						}
					}
				}
			}
		}
//	printf("%d %d\n",l,r);
//	printf("%d %d %d\n",Max1,Max2,Max3);
	int k;
	for(k=r+max((l+1)/2,(r-l+1)/2);k<r+min(l*2,(r-l)*2);k++){
		if(a[k-1].x-a[k].x==Max3)
		break;
	}
	int ans[3005];
	MEMS(ans);
	for(int i=0;i<l;i++)
	ans[a[i].y]=1;
	for(int i=l;i<r;i++)
	ans[a[i].y]=2;
	for(int i=r;i<k;i++)
	ans[a[i].y]=3;
	for(int i=0;i<n;i++)
	printf("%d ",ans[i]);
}