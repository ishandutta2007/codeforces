 #pragma GCC optimize("Ofast") 
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
    string s;
    while(cin>>s){
        if(s=="end")
        break;
        int l=0;
        int index=1;
        while(true){
            printf("? %d %d\n",l,l+index);
            fflush(stdout);
            cin>>s;
            if(s=="y"){
                l+=index;
                index*=2;
            }
            else{
                break;
            }
        }
        index/=2;
        while(index){
            printf("? %d %d\n",l,l+index);
            fflush(stdout);
            cin>>s;
            if(s=="y"){
                l+=index;
            }
            index/=2;
        }
        printf("! %d\n",l+1);
    }
}