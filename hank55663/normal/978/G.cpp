#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pair<pii,int>> v[105];
	int exam[105];
	fill(exam,exam+n+1,0);
	for(int i = 1;i<=m;i++){
		int s,d,c;
		scanf("%d %d %d",&s,&d,&c);
		v[s].pb(mp(mp(d,c),i));
		exam[d]=i;
	}
	int ok[105];
	fill(ok,ok+m+1,0);
	priority_queue<pair<pii,int> ,vector<pair<pii,int> >,greater<pair<pii,int> > > pq;
	int sch[105];
	fill(sch,sch+n+1,0);
	for(int i =1;i<=n;i++){
		for(auto it:v[i]){
			pq.push(it);
		}
		if(exam[i]){
			if(!ok[exam[i]]){
				printf("-1\n");
				return 0;
			}
			sch[i]=m+1;
			continue;
		}
		if(!pq.empty()){
			auto p=pq.top();
			pq.pop();
			sch[i]=p.y;
			p.x.y--;
			if(p.x.y==0){
				//printf("%d %d\n",i,p.y);
				ok[p.y]=1;
			}
			else{
				pq.push(p);
			}
		}
	}
	for(int i =1;i<=n;i++)
	printf("%d ",sch[i]);
}