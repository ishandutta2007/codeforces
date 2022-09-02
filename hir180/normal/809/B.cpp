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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	int L = 1,R = n;
	while(L != R){
		int mid = (L+R)/2;
		//[L,mid] [mid+1,R]
		printf("1 %d %d\n",mid,mid+1);
		fflush(stdout);
		string s; cin >> s;
		if(s == "TAK"){
			R = mid;
		}
		else{
			L = mid+1;
		}
	}
	int x = L,y,z;
	{
		L = 1,R = x-1;
		while(L < R){
			int mid = (L+R)/2;
			//[L,mid] [mid+1,R]
			printf("1 %d %d\n",mid,mid+1);
			fflush(stdout);
			string s; cin >> s;
			if(s == "TAK"){
				R = mid;
			}
			else{
				L = mid+1;
			}
		}
		y = L;
		
		L = x+1,R = n;
		while(L < R){
			int mid = (L+R)/2;
			//[L,mid] [mid+1,R]
			printf("1 %d %d\n",mid,mid+1);
			fflush(stdout);
			string s; cin >> s;
			if(s == "TAK"){
				R = mid;
			}
			else{
				L = mid+1;
			}
		}
		z = L;
		
		if(y!=x && y>0){
			printf("1 %d %d\n",y,x);
			fflush(stdout);
			string s; cin >> s;
			if(s != "TAK"){
				y = z;
			}
		}
		else y = z;
		printf("2 %d %d\n",x,y);
	}
}