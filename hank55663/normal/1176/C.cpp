#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
//	int q;
	//scanf("%d",&q);
	//while(q--){
		int n;
		scanf("%d",&n);
		int cnt[105];
		fill(cnt,cnt+105,0);
		for(int i = 0;i<n;i++){
			int x;
			scanf("%d",&x);
			if(x==4){
				cnt[4]++;
			}
			if(x==8&&cnt[4]){
				cnt[4]--;
				cnt[8]++;
			}
			if(x==15&&cnt[8]){
				cnt[8]--;
				cnt[15]++;
			}
			if(x==16&&cnt[15]){
				cnt[15]--;
				cnt[16]++;
			}
			if(x==23&&cnt[16]){
				cnt[16]--;
				cnt[23]++;
			}
			if(x==42&&cnt[23]){
				cnt[23]--;
				cnt[42]++;
			}
		}
		printf("%d\n",n-cnt[42]*6);
//	}
}
/*
aaaa
aaba
abaa
baaa
baba
*/