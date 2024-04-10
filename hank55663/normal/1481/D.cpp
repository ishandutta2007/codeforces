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
void solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	char c[1005][1005];
	for(int i = 1;i<=n;i++)scanf("%s",c[i]+1);
	if(m%2==1){
		printf("YES\n");
		for(int i=1;i<=m+1;i++){
			printf("%d ",i%2+1);
		}
		printf("\n");
	}
	else{
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					if(c[i][j]==c[j][i]){
						printf("YES\n");
						for(int k = 1;k<=m+1;k++){
							if(k%2==0)printf("%d ",i);
							else printf("%d ",j);
						}
						printf("\n");
						return;
					}
				}
			}
		}
		vector<int> v;
		for(int i = 1;i<=n;i++){
			for(int a=1;a<=n;a++){
				for(int b=1;b<=n;b++){
					if(c[i][a]==c[b][i]&&i!=a&&i!=b){
						v.pb(i);
						while(v.size()<=m){
							v.pb(a);
							v.pb(i);
							v.pb(b);
							v.pb(i);
						}
						if(v.size()==m+1){
							printf("YES\n");
							for(auto it:v)printf("%d ",it);
							printf("\n");
						}
						else{
							printf("YES\n");
							for(int i = 1;i+1<v.size();i++)printf("%d ",v[i]);
							printf("\n");
						}
						return;
					}
				}
			}
		}
		printf("NO\n");
	}
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*

*/