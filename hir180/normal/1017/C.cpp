#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int main(){
	cin>>n;
	for(int sum=2;;sum++){
		int x;
		if(sum%2 == 0) x = sum*sum/4;
		else x = (sum/2)*(sum/2+1);
		if(n <= x){
			int a = sum/2;
			int b = sum/2;
			if(a+b != sum) b++;
			int zan = n;
			for(int i=0;i<a;i++){
				int beg = zan-b+1;
				if(beg<1) beg = 1;
				for(int j=beg;j<=zan;j++){
					printf("%d ",j);
				}
				zan = beg-1;
			}puts("");
			assert(zan == 0) ; return 0;
		}
	}
}