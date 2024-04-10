#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int u,v;
	scanf("%d %d",&u,&v);
	if(u>v)printf("NO\n");
	else{
		int cnt=0;
		while(u||v){
			if(u&1)cnt++;
			if(v&1)cnt--;
			if(cnt<0){
				printf("NO\n");
				return false;
			}
			u>>=1;
			v>>=1;
		}
		printf("YES\n");
	}
}
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}