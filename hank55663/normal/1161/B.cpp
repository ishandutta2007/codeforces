#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pii> v;
	for(int i = 0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(b<a)
		swap(b,a);
		v.pb(mp(a,b));
	}
	sort(v.begin(),v.end());
	for(int i = 1;i<n;i++){
		if(n%i==0){
			vector<pii> temp;
			for(auto it:v){
				int x=(it.x+i-1)%n+1,y=(it.y+i-1)%n+1;
				if(x>y)
				swap(x,y);
				temp.pb(mp(x,y));
			}
			sort(temp.begin(),temp.end());
			int ok=1;
			for(int j=0;j<m;j++){
				if(temp[j]!=v[j]){
					ok=0;
					break;
				}
			}
			if(ok){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
}
/*

2*5!     240
2*4!*5   240
2*3!*10 120
2*2!*10 40
2*1!*5  10
2    2

*/