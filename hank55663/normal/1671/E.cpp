#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
char c[1000005];
const int mod=998244353;
int Max;
LL ans=1;
struct node{
	node *l,*r;
	char c;
	node(char a):l(NULL),r(NULL),c(a){

	}
}*root;
bool check(node *x,node *y){
	if(!x)return true;
	if(x->c!=y->c)return false;
	return check(x->l,y->l)&&check(x->r,y->r);
}
void dfs(node *n){
	if(!n)return;
	if(check(n->l,n->r));
	else ans=ans*2%mod;

	dfs(n->l);
	dfs(n->r);
}
vector<LL> base;
int rmod;
LL go(node *&n,int idx,int x){
	if(idx>Max){
		return 0;
	}
	n=new node(c[idx]);
	LL a=go(n->l,idx*2,x+1),b=go(n->r,idx*2+1,x+1);
	if(a>b){
		swap(a,b);
		swap(n->l,n->r);
	}
	LL val=c[idx]-'A'+1;
	return (val*base[x]%rmod*base[x]+a*base[x]%rmod+b)%rmod;
}
void solve(){
	rmod=rand()%1000000000+1000000000;
	while(true){
		int ok=1;
		for(int i = 2;i*i<=rmod;i++){
			if(rmod%i==0)ok=0;
		}
		if(ok)break;
		rmod++;
	}
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		base.pb(rand()%rmod);
	}
	Max=(1<<n)-1;
	scanf("%s",c+1);
	root=NULL;
	go(root,1,0);
	dfs(root);
	printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
//    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/