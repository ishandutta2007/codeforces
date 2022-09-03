#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ld long double
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
int main(){
	int n;
	scanf("%d",&n);
	map<int,int> m;
	int a[200005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		m[a[i]]=max(m[a[i]],m[a[i]-1]+1);
	}
	int Max=0,k=0;
	for(auto it:m){
		if(it.y>Max){
			Max=it.y;
			k=it.x;
		}
	}
	printf("%d\n",Max);
	int st=k-Max+1;
	for(int i = 0;i<n;i++){
		if(a[i]==st){
			printf("%d ",i+1);
			st++;
		}
	}
}