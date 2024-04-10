//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v;
	int ans=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a%2==0&&a>0)
		ans+=a;
		else if(a%2==1||a%2==-1)
		v.pb(a);
	}

	sort(v.begin(),v.end());
	ans+=v.back();
	for(int i=v.size()-2;i>=1;i-=2){
		if(v[i]+v[i-1]>=0)
			ans+=(v[i]+v[i-1]);
		else
		break;
	}
	printf("%d\n",ans);
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/