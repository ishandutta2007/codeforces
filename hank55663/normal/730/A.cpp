#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define x first
#define y second 
using namespace std;
int c[10005][200];
int party[10005];
int main() {
	int n;
	scanf("%d",&n);
	int ans=1e9;
	int r[300];
	priority_queue< pii, vector<pii> ,less<pii> > pq; 
	for(int i=0;i<n;i++){
		scanf("%d",&r[i]);
		ans=min(ans,r[i]);
		pq.push(mp(r[i],i));
	}
	memset(c,0,sizeof(c));
	memset(party,0,sizeof(party));
	int t=0;
	while(pq.top().x!=ans){
		pii p1=pq.top();
		pq.pop();
		pii p2=pq.top();
		pq.pop();
		if(p2.x==ans){
			for(int i=0;i<t&&p1.x!=ans;i++){
				if(party[i]<5&&c[i][p1.y]==0)
				{
					c[i][p1.y]=1;
				//	printf("%d",p1.y);
					party[t]++;
					p1.x--;
				}
			}
			if(p1.x!=ans&&ans!=0)
			ans--;
			else if(p1.x==ans)
			break;
		}
		c[t][p1.y]=1;
		c[t][p2.y]=1;
		p1.x--;
		if(p1.x<0)
		p1.x++;
		p2.x--;
		if(p2.x<0)
		p2.x++;
		pq.push(p1);
		pq.push(p2);
		party[t]=2;
		t++;
	}
	printf("%d\n%d\n",ans,t);
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++)
		printf("%d",c[i][j]);
		printf("\n"); 
	}
}