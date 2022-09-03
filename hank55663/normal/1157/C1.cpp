/*#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i = 0;i<n;i++)
	scanf("%d",&a[i]);
	int l =0,r=n-1;
	vector<char> v1,v2;
	vector<int> vv1,vv2;
	vv1.pb(0);
	vv2.pb(0);
	while(l<=r){
		if(a[l]<a[r]&&a[l]>vv1.back()){
			vv1.pb(a[l]);
			v1.pb('L');
			l++;
		}
		else if(a[r]>vv1.back()){
			vv1.pb(a[r]);
			v1.pb('R');
			r--;
		}
		else if(a[l]>vv1.back()){
			vv1.pb(a[l]);
			v1.pb('L');
			l++;
		}
		else{
			break;
		}
	}
	l =0,r=n-1;
	while(l<=r){
		if(a[l]<=a[r]&&a[l]>vv2.back()){
			vv2.pb(a[l]);
			v2.pb('L');
			l++;
		}
		else if(a[r]>vv2.back()){
			vv2.pb(a[r]);
			v2.pb('R');
			r--;
		}
		else if(a[l]>vv2.back()){
			vv2.pb(a[l]);
			v2.pb('L');
			l++;
		}
		else{
			break;
		}
	}
	if(v1.size()<v2.size()){
		swap(v1,v2);
	}
	printf("%d\n",v1.size());
	for(auto it:v1)
	printf("%c",it);
	printf("\n");
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/