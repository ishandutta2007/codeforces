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
	int n;
	pll p[5005];
	int vis[5005];
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		LL x,y;
		scanf("%lld %lld",&x,&y);
		p[i]=mp(x,y);
	}
	vector<int> v;
	v.pb(0);
	fill(vis,vis+n+1,0);
	vis[0]=1;
	for(int i =1;i<n;i++){
		LL Max=0;
		int Maxi;
		for(int j=0;j<n;j++){
			if(!vis[j]){
				LL d=sqr(p[v.back()].x-p[j].x)+sqr(p[v.back()].y-p[j].y);
				if(d>Max){
					Max=d;
					Maxi=j;
				}
			}
		}
		v.pb(Maxi);
		vis[Maxi]=1;
	}
	for(auto it:v){
		printf("%d ",it+1);
	}
}
int main(){
    int t=1;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/