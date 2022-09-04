#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 300005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
//#include<bits/stdc++.h>
//using namespace std;
int mod = 1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	int a[N];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]); 
	sort(a,a+n);
	LL pro=1,add=0;
	for(int i=0;i<n;i++){
		add+=pro*a[i];
		add%=mod;
		pro<<=1;
		pro%=mod;
	}
	reverse(a,a+n);
	pro=1;
	LL sub=0;
	for(int i=0;i<n;i++){
		sub+=pro*a[i];
		sub%=mod;
		pro<<=1;
		pro%=mod;
	}
	printf("%I64d\n",((add-sub)%mod+mod)%mod);
}