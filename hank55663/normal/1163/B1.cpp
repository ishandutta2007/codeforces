#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	map<int,int> m;
	map<int,int> cnt;
	int ans = 0;
	int Max = 1;
	cnt[0]=1e5;
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[m[x]]--;
		m[x]++;
		cnt[m[x]]++;
		Max=max(Max,m[x]);
		if(cnt[Max]+cnt[Max-1]+cnt[0]==1e5&&cnt[Max]==1){
			ans=i+1;
		}
		if(cnt[Max]+cnt[1]+cnt[0]==1e5&&cnt[1]==1){
			ans=i+1;
		}
		if(cnt[1]+cnt[0]==1e5){
			ans=i+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}