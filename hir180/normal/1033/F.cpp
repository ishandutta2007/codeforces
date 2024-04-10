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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int cnt[9*9*9*9*9*9+5],val[4096];
int w,n,m,a[30005];
int th[15];
char strr[16];
int ans[4096];
int num[4096];
int rev[5000];
int main(){
	scanf("%d%d%d",&w,&n,&m); 
	th[0] = 1;
	for(int i=1;i<=14;i++) th[i] = th[i-1]*3;
	for(int i=0;i<=12;i++) rev[(1<<i)] = i;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		val[a[i]]++;
	}
	for(int i=0;i<th[w];i++){
		int cur = i;
		int look = -1;
		int mask = 0;
		for(int j=0;j<w;j++){
			int rem = cur%3;
			cur /= 3;
			if(rem == 2){
				look = j;
			}
			else mask += (1<<j)*rem;
		}
		if(look == -1){
			cnt[i] = val[mask];
		}
		else{
			cnt[i] = cnt[i-th[look]]+cnt[i-th[look]*2];
		}
	}
	for(int ii=0;ii<m;ii++){
		scanf("%s",&strr);
		int str[16];
		for(int j=0;j<w;j++){
			if(strr[j] == 'A') str[j] = 0;
			else if(strr[j] == 'O') str[j] = 1;
			else if(strr[j] == 'X') str[j] = 2;
			else if(strr[j] == 'a') str[j] = 3;
			else if(strr[j] == 'o') str[j] = 4;
			else if(strr[j] == 'x') str[j] = 5;
		}
		ll ret = 0;
		for(int i=0;i<(1<<w);i++){
			if(i == 0){
				int check = 0;
				int fail = 0;
				for(int j=0;j<w;j++){
					if(str[w-1-j] == 0){
						check += th[j]*2;
					}
					else if(str[w-1-j] == 1 || str[w-1-j] == 2){
					}
					else if(str[w-1-j] == 3){
						fail += 1;
					}
					else if(str[w-1-j] == 4 || str[w-1-j] == 5){
						check += th[j]*1;
					}
				}
				if(!fail) ret += cnt[check]*val[i];
				ans[i] = check;
				num[i] = fail;
			}
			else{
				int jj = (i&-i);
				int check = ans[i-jj];
				int fail = num[i-jj];
				int j = rev[jj];
					
					if(str[w-1-j] == 4){
						check += th[j]*2;
					}
					else if(str[w-1-j] == 0 || str[w-1-j] == 5){
					}
					else if(str[w-1-j] == 1){
						fail += 1;
					}
					else if(str[w-1-j] == 2 || str[w-1-j] == 3){
						check += th[j]*1;
					}
					
					if(str[w-1-j] == 0){
						check -= th[j]*2;
					}
					else if(str[w-1-j] == 1 || str[w-1-j] == 2){
					}
					else if(str[w-1-j] == 3){
						fail -= 1;
					}
					else if(str[w-1-j] == 4 || str[w-1-j] == 5){
						check -= th[j]*1;
					}
				if(!fail) ret += cnt[check]*val[i];
				ans[i] = check;
				num[i] = fail;
			}
		}
		printf("%lld\n",ret);
	}
}