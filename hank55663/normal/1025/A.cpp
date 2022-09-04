#pragma (-Ofast )
#pragma unroll
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
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
#define N 500005
vector<int> v[5][1005];
int mod=1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("YES\n");
		return 0;
	}
	char c[100005];
	scanf("%s",c);
	int cnt[26];
	MEM(cnt);
	for(int i=0;c[i]!=0;i++){
		if(cnt[c[i]-'a']){
			printf("YES\n");
			return 0;
		}
		cnt[c[i]-'a']++;
	}
	printf("NO\n");
}
/*
1 2 3 3 2 1 =6
1 2 4       12
1 3 3       3
1 3 4       8
2 2 3       4
2 2 4       9
2 3 3       2
2 3 4       6

*/