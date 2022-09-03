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
vector<int> v[4][150005];
int c[4][150005];
int val[4][150005];
void solve(){
	//multiset<int> s[4];
	int a[4];
	for(int i = 0;i<4;i++)scanf("%d",&a[i]);
	for(int i = 0;i<4;i++){
		for(int j = 1;j<=a[i];j++){
			int x;
			scanf("%d",&x);
	//		if(i==0)
	//		s[i].insert(x);
			c[i][j]=x;
		}
	}
	for(int i = 1;i<4;i++){
		int m;
		scanf("%d",&m);
		for(int j = 0;j<m;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			v[i][b].pb(a);
		}
	}
	multiset<int> s;
	for(int i = 1;i<=a[0];i++)s.insert(c[0][i]),val[0][i]=c[0][i];
	for(int i = 1;i<4;i++){
		for(int j = 1;j<=a[i];j++){
			for(auto it:v[i][j]){
				s.erase(s.find(val[i-1][it]));
			}
			if(s.size())
			val[i][j]=*s.begin()+c[i][j];
			else{
				val[i][j]=5e8;
			}
			for(auto it:v[i][j]){
				s.insert(val[i-1][it]);
			}
		}
		s.clear();
		for(int j = 1;j<=a[i];j++){
			s.insert(val[i][j]);
		}
	}
	int Min=1e9;
	for(int i = 1;i<=a[3];i++)Min=min(Min,val[3][i]);
	if(Min>=5e8)printf("-1\n");
	else printf("%d\n",Min);
}
int main(){
    int t=1;00000;//00000;
  //  scanf("%d",&t);
    while(t--)solve();
}
/*
1 2 3 4 5 6 7
1 3 5 7 2 4 6
0 3 6 2 5 1 4
*/