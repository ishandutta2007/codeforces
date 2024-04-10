#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=1e5+20;
const int M=998244353;
int _,n,m,x,a[maxn],sum[maxn],ans[maxn];
priority_queue <pi, vector<pi>, greater<pi> > q;
int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d%d",&n,&m,&x);
		while (!q.empty()) q.pop();
		for (int i=1;i<=m;i++){
			sum[i]=0;
			q.push((pi){sum[i],i});
		}
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			pi tmp=q.top(); q.pop();
			int id=tmp.S;
			ans[i]=id;
			sum[id]+=x;
			q.push((pi){sum[id],id});
		}
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
	}
	return 0;
}