#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define right RRR
#define left LLL
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[105][105];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	vector<int> row,col;
	if(m>n){
		int mi=1e9;
		for(int i=0;i<n;i++){
			mi=1e9;
			for(int j=0;j<m;j++)
				mi=min(mi,a[i][j]);
			for(int j=0;j<mi;j++)
			row.pb(i+1);
			for(int j=0;j<m;j++)
			a[i][j]-=mi;
		}
		for(int i=0;i<m;i++){ 
			int b=a[0][i];
			for(int j=1;j<n;j++){
				if(a[j][i]!=b)
				{
					printf("-1\n");
					return 0;
				}
			}
			for(int j=0;j<b;j++)
			col.pb(i+1); 
		} 
		printf("%d\n",col.size()+row.size());
		for(vector<int>::iterator it=row.begin();it!=row.end();it++)
		printf("row %d\n",*it);
		for(vector<int>::iterator it=col.begin();it!=col.end();it++)
		printf("col %d\n",*it);
	}
	else{
		int mi=1e9;
		swap(n,m);
		for(int i=0;i<n;i++){
			mi=1e9;
			for(int j=0;j<m;j++)
				mi=min(mi,a[j][i]);
			for(int j=0;j<mi;j++)
			col.pb(i+1);
			for(int j=0;j<m;j++)
			a[j][i]-=mi;
		}
		for(int i=0;i<m;i++){ 
			int b=a[i][0];
			for(int j=1;j<n;j++){
				if(a[i][j]!=b)
				{
					printf("-1\n");
					return 0;
				}
			}
			for(int j=0;j<b;j++)
			row.pb(i+1); 
		} 
		printf("%d\n",col.size()+row.size());
		for(vector<int>::iterator it=row.begin();it!=row.end();it++)
		printf("row %d\n",*it);
		for(vector<int>::iterator it=col.begin();it!=col.end();it++)
		printf("col %d\n",*it);
	}
}