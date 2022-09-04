#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct node{
	node *n[2];
	int cnt;
	node(){
		n[0]=n[1]=NULL;
		cnt=0;
	}
}*root;
void add(int a){
	int num[30];
	for(int i=29;i>=0;i--){
		num[i]=a&1;
		a>>=1;
	}
	node *n =root;
	for(int i=0;i<30;i++){
		if(!n->n[num[i]])n->n[num[i]]=new node();
		n=n->n[num[i]];
		n->cnt++;
	}
}
int search(int a){
	int num[30];
	for(int i=29;i>=0;i--){
		num[i]=a&1;
		a>>=1;
	}
	int ans=0;
	node *n=root;
	for(int i=0;i<30;i++){
		ans*=2;
		if(!n->n[num[i]]||n->n[num[i]]->cnt==0){
			n=n->n[1-num[i]];
			ans++;
		}
		else{
			n=n->n[num[i]];
		}
		n->cnt--;
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	root=new node();
	int a[300005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int j=0;j<n;j++){
		int b;
		scanf("%d",&b);
		add(b);
	}
	for(int i=0;i<n;i++)
	printf("%d ",search(a[i]));
}