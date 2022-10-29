#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAX (1ll<<61)

set<pil> st;
ll h,a[100005];
int n,m,k,c[100005];
ll dis[10005];
vector<ll> tt;
priority_queue<pli> q;
bool use[100005];
int  mmm[100005];

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	scanf("%I64d%d%d%d",&h,&n,&m,&k);
	for(int i=0;i<n;++i) scanf("%I64d%d",a+i,c+i),mmm[i]=(a[i]-1)%k;
	for(int i=0;i<n;++i) if(mmm[i]==0)
		st.insert(mp(-c[i],i)),use[i]=1;
	for(int z=0;z<m;++z) {
		int op,x,y;
		scanf("%d",&op);
		if(op==1) {
			ll xx;
			scanf("%I64d",&xx),tt.push_back(xx);
			for(int i=0;i<k;++i) dis[i]=MAX;
			dis[0]=0,q.push(mp(0,0));
			while(q.size()) {
				int u=q.top().se;
				q.pop();
				for(int i=0;i<tt.size();++i) {
					ll add=tt[i];
					int v=(u+add)%k;
					if(dis[v]>dis[u]+add) {
						dis[v]=dis[u]+add,q.push(mp(-dis[v],v));
					}
				}
			}
			for(int i=0;i<n;++i) if(!use[i] && dis[mmm[i]]<=a[i]-1) {
				use[i]=1,st.insert(mp(-c[i],i));
			}
		}
		else if(op==2) {
			scanf("%d%d",&x,&y),x--;
			if(st.count(mp(-c[x],x))) {
				st.erase(st.find(mp(-c[x],x)));
				c[x]-=y;
				st.insert(mp(-c[x],x));
			}
			else c[x]-=y;
		}
		else {
			if(st.size()==0) printf("0\n");
			else {
				printf("%d\n",-(st.begin()->first));
				st.erase(st.begin());
			}
		}
	}
}