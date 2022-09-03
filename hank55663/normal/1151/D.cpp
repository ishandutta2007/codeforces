#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
typedef complex<double> C;
bool cmp(const pii &a,const pii &b){
	return a.x-a.y>b.x-b.y;
}
int main()
{
	int n;
	scanf("%d",&n);
	pii p[100005];
	for(int i = 0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	sort(p,p+n,cmp);
	LL ans=0;
	for(int i = 0;i<n;i++){
		ans+=(LL)p[i].x*i+(LL)p[i].y*(n-i-1);
	}
	printf("%lld\n",ans);
}