#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<map>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	map<int,int> m;
	LL ans=0;
	char c[1000005];
	for(int i=0;i<n;i++){
		scanf("%s",c);
		int cnt[26];
		MEM(cnt);
		for(int j=0;c[j]!=0;j++)
		cnt[c[j]-'a']++;
		int num=0;
		for(int i=0;i<26;i++){
			num<<=1;
			num+=cnt[i]%2;
		}
		//printf("%d\n",num);
		ans+=m[num];
		for(int j=0;j<26;j++){
			ans+=m[num^(1<<j)];
		}
		m[num]++;
	}
	printf("%lld\n",ans);
}