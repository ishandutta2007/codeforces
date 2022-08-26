#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef double db;
const int M=998244353;
const int maxn=1e6+10;
int _,n,m,cnt[maxn],ans[maxn],mx,p;
vector<int> a[maxn];
int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d",&n,&m);
		mx=(m+1)/2;
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=1;i<=m;i++){
			a[i].clear();
			int sz;scanf("%d",&sz);
			for (int j=0;j<sz;j++){
				int x;scanf("%d",&x);
				a[i].pb(x);
			}
			ans[i]=a[i][0];
			cnt[ans[i]]++;
		}
		int id=-1;
		for (int i=1;i<=n;i++) if (cnt[i]>mx) id=i;
		if (id==-1){
			puts("YES");
			for (int i=1;i<=m;i++) printf("%d ",ans[i]);puts("");
		} else {
            for (int i=1;i<=m;i++){
				if (ans[i]==id&&a[i].size()>=2){
                    ans[i]=a[i][1];
                    cnt[id]--;
                    if (cnt[id]<=mx) break;
				}
            }
            if (cnt[id]>mx){puts("NO");}
            else {
				puts("YES");
				for (int i=1;i<=m;i++) printf("%d ",ans[i]);puts("");
            }
		}
	}
	return 0;
}