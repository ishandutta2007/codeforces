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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    vector<int> v[2005];
    for(int i=0;i<n;i++)
    v[i%p].pb(i);
    char c[2005];
    scanf("%s",c);
    int ok=0;
    for(int i=0;i<p;i++){
        char word='0';
        for(auto it:v[i]){
            if(c[it]!='.'){
                word='1'-c[it]+'0';
                break;
            }
        }
        for(auto it:v[i]){
            if(c[it]=='.'){
                c[it]=word;
                word='1'-word+'0';
            }
        }
        word=c[v[i][0]];
        for(auto it:v[i]){
            if(c[it]!=word){
                ok=1;
            }
        }
    }
    if(ok)
    printf("%s\n",c);
    else
    printf("NO\n");
}