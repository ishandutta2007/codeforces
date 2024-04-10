#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=30005;
const int L=100;
ll cnt[maxn][5],l[maxn][5],r[maxn][5],sl[maxn][5],sr[maxn][5];
int _,n,p[maxn],m,q;
void solve(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int j=0;j<=m;j++) cnt[n+1][j]=1;
	for (int i=n;i;i--){
        for (int j=0;j<=m;j++){
            cnt[i][j]=cnt[i+1][j];
            for (int k=1;k<=j;k++)
				if (i+k<=n) cnt[i][j]+=cnt[i+k+1][j-k];
        }
	}

	for (int i=1;i<=n;i++)
	for (int j=0;j<=m;j++){
        ll x=0,y=0;
		for (int w=1;w<=j&&i+w<=n;w++){
			if (p[i+w]<p[i]) x+=cnt[i+w+1][j-w];
			else y+=cnt[i+w+1][j-w];
        }
        l[i][j]=x;
        r[i][j]=y;
        sl[i][j]=sl[i-1][j]+x;
        sr[i][j]=sr[i-1][j]+y;
	}
	while (q--){
		ll t; int pos,now,cost;
		scanf("%d%lld",&pos,&t);
		if (t>cnt[1][m]){puts("-1");continue;}
		now=1; cost=m;
		while (now<=pos){
            if (t>l[now][cost]&&t<=cnt[now][cost]-r[now][cost]){
				int L=now,R=n+1;
				while (R-L>1){
					int mid=(L+R)>>1;
					ll u=sl[mid][cost]-sl[now-1][cost];
					ll v=sr[mid][cost]-sr[now-1][cost];
					if (t>u&&t<=cnt[now][cost]-v) L=mid; else R=mid;
				}
				t-=sl[L][cost]-sl[now-1][cost];now=R;
				if (now>pos) printf("%d\n",p[pos]);
            } else {
				vector<pi> A; A.clear();
				for (int i=0;i<=cost&&i+now<=n;i++)
					A.pb((pi){p[i+now],i});
				sort(A.begin(),A.end());
				for (auto x:A){
					ll cc=cnt[x.S+now+1][cost-x.S];
					if (t<=cc) {
						if (pos>=now&&pos<=now+x.S){
                            printf("%d\n",p[now+now+x.S-pos]);
						}
						now+=x.S+1;
						cost-=x.S;
                        break;
					}
					t-=cc;
				}
            }
		}
	}
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}