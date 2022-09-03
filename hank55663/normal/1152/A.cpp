#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt[2];
	cnt[0]=cnt[1]=0;
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x&1]++;
	}
	int ans=0;
	for(int j =0;j<m;j++){
		int x;
		scanf("%d",&x);
		if(cnt[(x+1)&1]){
			ans++;
			cnt[(x+1)&1]--;
		}
	}
	printf("%d\n",ans);
}