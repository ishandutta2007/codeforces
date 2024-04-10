#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
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
#define BLOCK 100
int n,w,q;
int a[100005];
P query[100005];
//
int cnt[100005];
//min / max
int mn[100005],mx[100005];
// -> n^4/3
int lim[100005];
//lim
int lim_min[1005];
//
int nxtt[100005];
//
int last[100005];

int ans[100005];
int MN[100005][20],MX[100005][20];

int calc(int &mn,int &mx,int lim,int num,int &ans){
	int L = (num+1)*BLOCK;
	int R = (num+2)*BLOCK; R = min(R,n);
	//[L,R)
	int len = R-L;
	int pos = L;
	for(int i=6;i>=0;i--){
		if((1<<i) > len) continue;
		if(max(mx,MX[pos][i])-min(mn,MN[pos][i]) <= lim){
			mx = max(mx,MX[pos][i]);
			mn = min(mn,MN[pos][i]);
			pos += (1<<i);
			len -= (1<<i);
		}
	}
	if(pos < R){
		mn = INF; mx = -INF;
		ans++;
		return pos;
	}
	else{
		return R-1;
	}
}
int main(){
	scanf("%d%d%d",&n,&w,&q);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) MN[i][0] = MX[i][0] = a[i];
	for(int j=0;j<19;j++) for(int i=0;i<n;i++){
		if(i+(1<<j) >= n){
			MN[i][j+1] = MN[i][j];
			MX[i][j+1] = MX[i][j];
		}
		else{
			MN[i][j+1] = min(MN[i][j],MN[i+(1<<j)][j]);
			MX[i][j+1] = max(MX[i][j],MX[i+(1<<j)][j]);
		}
	}
	for(int i=0;i<q;i++){
		int a; scanf("%d",&a); query[i]=mp(w-a,i);
	}
	sort(query,query+q);
	int sz = (n-1)/BLOCK+1;
	rep(i,sz){
		int beg = i*BLOCK;
		int en = (i+1)*BLOCK; en = min(en,n);
		lim_min[i] = INF;
		for(int j=en-1;j>=beg;j--){
			int curmn = a[j],curmx = a[j];
			int nxt = j+1;
			while(nxt < en && max(curmx,a[nxt])-min(curmn,a[nxt])<=0){
				curmn = min(curmn,a[nxt]);
				curmx = max(curmx,a[nxt]);
				nxt++;
			}
			if(nxt >= en){
				//
				cnt[j] = 0;
				mn[j] = curmn;
				mx[j] = curmx;
				lim[j] = INF;
				nxtt[j] = INF;
				last[j] = j;
			}
			else{
				//nxt-1nxt
				cnt[j] = cnt[nxt]+1;
				mn[j] = curmn;
				mx[j] = curmx;
				lim[j] = max(curmx,a[nxt])-min(curmn,a[nxt]);
				lim_min[i] = min(lim_min[i],lim[j]);
				nxtt[j] = nxt;
				last[j] = last[nxt];
			}
		}
	}
	rep(x,q){
		int cur = query[x].fi;
		rep(j,sz){
			if(lim_min[j] <= cur){
				//1
				//
				for(int i=j;i<=j;i++){
					int beg = i*BLOCK;
					int en = (i+1)*BLOCK; en = min(en,n);
					lim_min[i] = INF;
					for(int j=en-1;j>=beg;j--){
						int curmn = mn[j],curmx = mx[j];
						int nxt = nxtt[j];
						while(nxt < en && max(curmx,a[nxt])-min(curmn,a[nxt])<=cur){
							curmn = min(curmn,a[nxt]);
							curmx = max(curmx,a[nxt]);
							nxt++;
						}
						if(nxt >= en){
							//
							cnt[j] = 0;
							mn[j] = curmn;
							mx[j] = curmx;
							lim[j] = INF;
							nxtt[j] = INF;
							last[j] = j;
						}
						else{
							//nxt-1nxt
							cnt[j] = cnt[nxt]+1;
							mn[j] = curmn;
							mx[j] = curmx;
							lim[j] = max(curmx,a[nxt])-min(curmn,a[nxt]);
							lim_min[i] = min(lim_min[i],lim[j]);
							nxtt[j] = nxt;
							last[j] = last[nxt];
						}
					}
				}
				assert(lim_min[j] > cur);
			}
		}
		int &ret = ans[query[x].sc];
		int mnv=INF,mxv=-INF,beg=0;
		for(int j=0;j<sz;j++){
			ret += cnt[beg]; 
			mnv = min(mnv,mn[last[beg]]);
			mxv = max(mxv,mx[last[beg]]);
			if(j+1 == sz){
				//ret++;
				break;
			}
			else{
				//beg
				beg = calc(mnv,mxv,query[x].fi,j,ret);
			}
		}
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
}