#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	set<string> s;
	for(int i=0;i<n;i++){
		string c;
		cin>>c;
		if(s.find(c)==s.end()){
			printf("NO\n");
			s.insert(c);
		}
		else{
			printf("YES\n");
		}
	}
}