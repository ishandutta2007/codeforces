#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int main(){
    int x1,y1;
    scanf("%d %d",&x1,&y1);
    int x2,y2;
    scanf("%d %d",&x2,&y2);
    x2-=x1;
    y2-=y1;
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    int totx=0,toty=0;
    for(auto it:s){
        if(it=='U')
        toty++;
        if(it=='D')
        toty--;
        if(it=='R')
        totx++;
        if(it=='L')
        totx--;
    }
    LL ans=1e18;
    LL nowx=0,nowy=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U'){
            nowy++;
        }
        if(s[i]=='D'){
            nowy--;
        }
        if(s[i]=='R'){
            nowx++;
        }
        if(s[i]=='L'){
            nowx--;
        }
        LL Max=1e13,Min=-1;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            LL x=totx*mid+nowx,y=toty*mid+nowy;
            LL dis=abs(x2-x)+abs(y2-y);
            LL step=i+1+n*mid;
            if(dis<=step){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        if(Max!=1e13)
        ans=min(ans,Max*n+i+1);
    }
    if(ans==1e18)
    printf("-1\n");
    else
    {
        printf("%lld\n",ans);
    }
    
}
/*

i f f x f l b
*/