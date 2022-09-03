#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	pii p[1005];
	int ori[1005];
	for(int i = 0;i<n;i++){
		int x;
		
		scanf("%d",&x);
		ori[i]=x;
		p[i]=mp(x,i);
	}
	vector<pii> need;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(p[i].x>p[j].x)need.pb(mp(i,j));
		}
	}
	sort(p,p+n);
	int a[1005];
	for(int i = 0;i<n;i++){
		a[p[i].y]=i;
	}
	vector<pii> ans;
	for(int  i = n-1;i>=0;i--){
		vector<pii> tmp;
		for(int j = i-1;j>=0;j--){
			if(a[j]>a[i]){
				tmp.pb(mp(a[j],j));
			}
		}
		sort(tmp.begin(),tmp.end());
		for(auto it:tmp){
			ans.pb(mp(it.y,i));
		}
	}
	printf("%d\n",ans.size());
	for(auto it:ans){
		printf("%d %d\n",it.x+1,it.y+1);
		swap(ori[it.x],ori[it.y]);
	}
	sort(ans.begin(),ans.end());
	assert(ans==need);
	for(int i = 0;i<n-1;i++){
		assert(ori[i]<=ori[i+1]);
	}
	return 0;
}