#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int cnt[5005];
	vector<int> v[5005];
	MEM(cnt);
	pii p[5005];
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
		for(int j=x;j<=y;j++)
		cnt[j]++,v[j].pb(i);
	}
	int cnt2[5005];
	int ans=0;
	for(int i=0;i<q;i++){
		MEM(cnt2);
		for(int j=p[i].x;j<=p[i].y;j++)
		cnt[j]--;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(cnt[j])
			sum++;
			if(cnt[j]==1){
				for(auto it:v[j]){
					if(it!=i)
					cnt2[it]++;
				}
			}
		}
		for(int j=0;j<q;j++)
		if(i!=j)
		ans=max(ans,sum-cnt2[j]);
		for(int j=p[i].x;j<=p[i].y;j++)
		cnt[j]++;
	}
	printf("%d\n",ans);
}