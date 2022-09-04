#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 1000005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	pair<int,string> p[100];
	int a=20000,ok=1;
	for(int i=0;i<n;i++){
		scanf("%d",&p[i].x);
		cin>>p[i].y;
		if(a==20000||a==0){
			if(p[i].y=="East"||p[i].y=="West")
			ok=0;
			if(a==20000&&p[i].y=="North")
			ok=0;
			if(a==0&&p[i].y=="South")
			ok=0;
		}
		if(p[i].y=="North")
			a+=p[i].x;
		if(p[i].y=="South")
			a-=p[i].x;
		if(a>20000||a<0)
		ok=0;
	}
	if(a!=20000)
	ok=0;
//	printf("%d",a);
	printf("%s\n",ok?"YES":"NO");
	
}