#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
const int N=1e6+1;
int n,cur,tag[N],ans[N];
ll k,sum;
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	cin>>n>>k;
	if(k*2<1ll*n*(n+1))return cout<<"-1",0;
	sum=1ll*n*(n+1)/2;
	FOR(i,1,n){
		sum-=i;
		if(k-(n-i+1)>=sum)k-=n-i+1,ans[i]=n-i+1;
		else{
			ans[i]=k-sum,sum=0;
			FOR(j,i+1,n)ans[j]=j-i+(j-i>=ans[i]);
			break;
		}
	}
	FOR(i,1,n)sum+=max(i,ans[i]);
	cout<<sum<<'\n';
	FOR(i,1,n)cout<<i<<" \n"[i==n];
	FOR(i,1,n)cout<<ans[i]<<' ';
	return 0;
}