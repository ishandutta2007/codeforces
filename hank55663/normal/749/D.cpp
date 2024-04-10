#include<bits/stdc++.h>
#define time Time
#define pii pair<int,int>    
#define x first    
#define y second 
#define N 200005   
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
const int mod=1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	pii p[N];
	vector<int> v[N];
	int vv[N];
	memset(vv,0,sizeof(vv));
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		p[i]=mp(a,b);
		v[a].pb(i);
	}
	for(int i=n;i>=1;i--){
		if(!vv[p[i].x]){
			vv[p[i].x]=1;
			ans.pb(p[i].x);
		}
	}
	int q;
	scanf("%d",&q);
	int a[N];
	int visit[N];
	memset(visit,-1,sizeof(visit));
	while(q--){
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		scanf("%d",&a[i]),visit[a[i]]=q;
		vector<int>::iterator it=ans.begin();
		while(it!=ans.end()){
		if(visit[*it]!=q)break;
		else it++;
		}
		if(it==ans.end()){
			printf("0 0\n");
			continue;
		}
		int  mi=-1,ma=v[*it].size();
		while(ma>mi+1){
			int mid=v[*it][(ma+mi)/2];
			int sum=0;
			for(int i=0;i<k;i++){
				sum+=v[a[i]].end()-upper_bound(v[a[i]].begin(),v[a[i]].end(),mid);
			} 
			sum+=v[*it].end()-upper_bound(v[*it].begin(),v[*it].end(),mid);
			if(sum==n-mid)
			ma=(ma+mi)/2;
			else
			mi=(ma+mi)/2;
		//	printf("%d %d %d %d\n",ma,mi,mid,sum);
		}
		int index=v[*it][ma];
		printf("%d %d\n",p[index].x,p[index].y);
	}
}
/*

 1 - 1 + 2 + 10 - 2 + 3  + 5
 1  - 2  - 3  
*/