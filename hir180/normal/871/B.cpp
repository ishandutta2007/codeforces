#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int d[50005],e[50005];
int p[50005],b[50005];
bool used[50005],used2[50005];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		printf("? 0 %d\n",i);
		fflush(stdout);
		scanf("%d",&d[i]);
	}
	for(int i=0;i<n;i++){
		printf("? %d 0\n",i);
		fflush(stdout);
		scanf("%d",&e[i]);
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		//p_0 = i
		memset(used,0,sizeof(used));
		memset(used2,0,sizeof(used2));
		for(int j=0;j<n;j++){
			b[j] = d[j]^i;
			used[b[j]] = 1;
		}
		used2[i] = 1; p[0] = i;
		for(int j=1;j<n;j++){
			p[j] = e[j]^b[0];
			used2[p[j]] = 1;
		}
		for(int ii=0;ii<n;ii++){
			if(!used[ii] || !used2[ii]) goto fail;
			if(p[b[ii]] != ii) goto fail;
		//	if(i==3)cout<<ii<<endl;
		}
		cnt++; fail:;
	}
	puts("!");
	cout<<cnt<<endl;
	for(int i=0;i<n;i++){
		//p_0 = i
		memset(used,0,sizeof(used));
		memset(used2,0,sizeof(used2));
		for(int j=0;j<n;j++){
			b[j] = d[j]^i;
			used[b[j]] = 1;
		}
		used2[i] = 1; p[0] = i;
		for(int j=1;j<n;j++){
			p[j] = e[j]^b[0];
			used2[p[j]] = 1;
		}
		for(int i=0;i<n;i++){
			if(!used[i] || !used2[i]) goto fail2;
			if(p[b[i]] != i) goto fail2;
		}
		for(int i=0;i<n;i++) cout<<p[i]<<" ";
		cout<<endl; return 0;
		fail2:;
	}
}