#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long double,null_type,less<long double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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

struct statue{
	long double x,y;
    int xadd,ti;
	statue(long double _x,long double _y,int _xadd,int _ti):
	x(_x),y(_y),xadd(_xadd),ti(_ti){

	}
};
bool operator<(const statue &a,const statue &b){
    return a.ti<b.ti;
}
set_t t1,t2;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<statue> v;
	{
		int p[100005],s[100005],d[100005];
		for(int i = 0;i<n;i++)
			scanf("%d",&p[i]);
		for(int i = 0 ;i<n;i++)
			scanf("%d",&s[i]);
		for(int i = 0;i<n;i++)
			scanf("%d",&d[i]);
		for(int i = 0;i<n;i++){
			v.pb(statue((ld)p[i]+d[i]+i*1e-6,(ld)d[i]-p[i]+1+i*1e-6,1,p[i]));
			v.pb(statue((ld)p[i]+d[i]+i*1e-6,(ld)d[i]-p[i]+1+i*1e-6,-1,s[i]+1));
		}
	}
    sort(v.begin(),v.end());
    pair<pii,int> p[100005];
    for(int i =0;i<m;i++){
        scanf("%d",&p[i].x.x); 
    }
    for(int i = 0;i<m;i++){
        scanf("%d",&p[i].x.y);
        p[i].y=i;
    }
    sort(p,p+m);
	int now= 0;
	int ans[100005];
	for(int i = 0;i<m;i++){
		while(now!=v.size()&&v[now].ti<=p[i].x.x){
			double x=v[now].x,y=v[now].y;
			//cout<<"add "<<x<<" "<<y<<" "<<v[now].xadd<<endl;
			int xadd=v[now].xadd;
			if(xadd==1){
				t1.insert(x);
				t2.insert(y);
			}
			else{
				t1.erase(x);
				t2.erase(y);
			}
			now++;
		}
	//	printf("q %d %d %d\n",p[i].x.x+p[i].x.y,p[i].x.y-p[i].x.x,p[i].y);
		ans[p[i].y]=t1.order_of_key((ld)p[i].x.x+p[i].x.y+0.5);
	//	printf("%d %d\n",ans[p[i].y],t2.order_of_key(p[i].x.y-p[i].x.x+0.5));
		ans[p[i].y]-=t2.order_of_key((ld)p[i].x.y-p[i].x.x+0.5);
	}
	for(int i = 0;i<m;i++)
	printf("%d ",ans[i]);
	printf("\n");
}