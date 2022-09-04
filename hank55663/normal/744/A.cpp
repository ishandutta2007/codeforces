#include<bits/stdc++.h>
#define pii pair<int,int>        
#define x first        
#define y second        
#define pb(x) push_back(x)    
#define mp(x,y) make_pair((x),(y))        
#define sqr(x) ((x)*(x))    
typedef long long LL;      
using namespace std;  
vector<int> v[1005];     
int visit[1005];
int dfs(int n){
	visit[n]=1;
	int sum=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(!visit[*it])
		sum+=dfs(*it);
	}
	return sum;
}
int main(){    
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int gov[1005],size[1005];
	for(int i=0;i<k;i++)
	scanf("%d",&gov[i]);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	memset(visit,0,sizeof(visit));
	for(int i=0;i<k;i++)
	size[i]=dfs(gov[i]);
	sort(size,size+k);
	for(int i=1;i<=n;i++){
		if(!visit[i])
		size[k-1]+=dfs(i);
	}
	int ans=0;
	for(int i=0;i<k;i++)
	ans+=size[i]*(size[i]-1)/2;
	printf("%d",ans-m); 
}    
//3 1 2 5 4 3 4 5 1 4
//4 4 3 4 1 1 5 2 4 4
//4341524
//4565754121314