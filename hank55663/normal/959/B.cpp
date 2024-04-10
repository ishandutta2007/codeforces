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
typedef complex<double> C;
LL mod=1e9+7;
map<string,int> ma;
string str[100005];
int main()
{
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	for(int i =1;i<=n;i++){
		char c[25];
		scanf("%s",c);
		str[i]=string(c);
	}
	int value[100005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&value[i]);
	}
	int group[100005];
	for(int i = 0;i<k;i++){
		group[i]=1e9;
		int x;
		scanf("%d",&x);
		while(x--){
			int a;
			scanf("%d",&a);
			ma[str[a]]=i;
			group[i]=min(group[i],value[a]);
		}
	}
	LL ans=0;
	while(m--){
		char c[25];
		scanf("%s",c);
		string mystr(c);
		ans+=group[ma[mystr]];
	}
	printf("%lld\n",ans);
}