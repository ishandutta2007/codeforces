#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n,b,a;
	scanf("%d %d %d",&n,&b,&a);
	int cb=b,ca=a;
	int s[200005];
	for(int i = 0;i<n;i++)
	scanf("%d",&s[i]);
	int ans=0;
	for(;ans<n;ans++){
		if(s[ans]==0){
			if(ca)ca--;
			else if(cb)cb--;
			else break;
		}
		if(s[ans]==1){
			if(ca!=a){
				if(cb)cb--,ca++;
				else if(ca)ca--;
				else break;
			}
			else{if(ca) ca--;
			else if(cb) cb--;
			else break;
			}
		}
		//printf("%d %d\n",cb,ca);
	}
	printf("%d\n",ans);
}