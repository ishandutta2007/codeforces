#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int M=998244353;
const int base=19260817;
int a[1555][1555],b[1555][1555],va[1555],vb[1555],n,sum,m;
int deg[1555];
vector<int> G[1555];
bool flag[1555];
vector<int> ans,res;
queue<int> q;
void relax(int u){
	res.pb(u);
    for (int i=1;i<n;i++)
	if (!flag[i]&&b[i][u]<b[i+1][u]){
		flag[i]=1; sum++;
		for (auto j:G[i]){
			deg[j]--;
			if (!deg[j]) q.push(j);
		}
	}
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) scanf("%d",&b[i][j]);
	for (int i=1;i<=n;i++){
		a[i][m+1]=i;
		va[i]=0;
		for (int j=1;j<=m;j++) va[i]=(1ll*va[i]*base+a[i][j])%M;
		for (int j=1;j<=m;j++) vb[i]=(1ll*vb[i]*base+b[i][j])%M;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) if (!flag[j]&&va[j]==vb[i]){
			b[i][m+1]=j;
			flag[j]=1;
			break;
		}
		if (!b[i][m+1]){puts("-1");return 0;}
	}
	memset(flag,0,sizeof(flag));
    for (int i=1;i<=m+1;i++){
        for (int j=1;j<n;j++){
			if (b[j][i]>b[j+1][i]) G[j].pb(i),deg[i]++;
        }
    }
    sum=0;
    for (int i=1;i<=m+1;i++) if (!deg[i]){
		q.push(i);
    }
    while (!q.empty()){
		int u=q.front(); q.pop();
		relax(u);
		if (sum==n-1){
            break;
		}
    }
    if (sum<n-1){puts("-1");return 0;}
    for (auto x:res){
		if (x==m+1) break;
		ans.pb(x);
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (auto x:ans) printf("%d ",x);puts("");
    return 0;
}