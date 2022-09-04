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
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	LL n,q;
	scanf("%I64d %I64d",&n,&q);
	char c[100005];
	while(q--){
		LL a;
		scanf("%I64d",&a);
		stack<pll> s;
		pll p=mp(1,n);
		while(!s.empty())s.pop();
		while((p.x+p.y)/2!=a){
			s.push(p);
			if((p.x+p.y)/2>a)
			p=mp(p.x,(p.x+p.y)/2-1);
			else
			p=mp((p.x+p.y)/2+1,p.y);
		}
		scanf("%s",c);
		for(int i=0;c[i]!=0;i++){
			if(c[i]=='U'){
				if(!s.empty())
				{
					p=s.top();
					s.pop();
				}
			}
			else if(c[i]=='R'){
				if(p.x!=p.y){
				s.push(p);
				p=mp((p.x+p.y)/2+1,p.y);
				}
			}
			else{
				if(p.x!=p.y){ 
				s.push(p);
				p=mp(p.x,(p.x+p.y)/2-1);
				}
			}
		}
		printf("%I64d\n",(p.x+p.y)/2);
	}
}