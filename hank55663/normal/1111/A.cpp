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
    int ok[26];
    MEM(ok);
    ok['a'-'a']=1;
    ok['e'-'a']=1;
    ok['i'-'a']=1;
    ok['o'-'a']=1;
    ok['u'-'a']=1;
    char c[1005];
    char t[1005];
    scanf("%s",c);
    scanf("%s",t);
    if(strlen(c)!=strlen(t)){
        printf("NO\n");
    }
    else{
        for(int i=0;c[i]!=0;i++){
            if(c[i]!=t[i]){
                if(ok[c[i]-'a']!=ok[t[i]-'a']){
                    printf("NO\n");
                    return 0;
                }
            }
        }
        printf("YES\n");
    }
}
/*

i f f x f l b
*/