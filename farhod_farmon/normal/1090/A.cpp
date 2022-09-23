#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
ll ans=0;
int d[MAXN],arr[MAXN],idx[MAXN];
bool cmp(int x,int y){
	return (d[x]<d[y]);	
}
int main(){
    //freopen("file.in", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int x;
		scanf("%d",&x);
		arr[i]=x;
		while(x--){
			int y;
			scanf("%d",&y);
			umax(d[i],y);
		}
		idx[i]=i;
    }
    sort(idx+1,idx+n+1,cmp);
    ll cnt=0;
    for(int i=1;i<n;i++){
    	cnt+=arr[idx[i]];
    	ans+=cnt*1LL*(d[idx[i+1]]-d[idx[i]]);
    }
	printf("%lld\n",ans);					
	return 0;
}