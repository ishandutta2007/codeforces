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
    char t[10005];
    scanf("%s",t);
    int n=strlen(t);
    char temp[3][10005];
    MEM(temp);
    char now[4]="aaa";
    for(int i=0;i<n;i++){
        temp[0][i]=now[0];
        temp[1][i]=now[1];
        temp[2][i]=now[2];
        now[2]++;
        if(now[2]>'z'){
            now[2]='a';
            now[1]++;
        }
        if(now[1]>'z'){
            now[1]='a';
            now[0]++;
        }
    }
    char res[3][10005];
    printf("? %s\n",temp[0]);
    fflush(stdout);
    scanf("%s",res[0]);
    printf("? %s\n",temp[1]);
    fflush(stdout);
    scanf("%s",res[1]);
    printf("? %s\n",temp[2]);
    fflush(stdout);
    scanf("%s",res[2]);
    int num[10005];
    char ans[10005];
    MEM(ans);
    for(int i=0;i<n;i++){
        num[i]=(res[0][i]-'a')*26*26+(res[1][i]-'a')*26+res[2][i]-'a';
        ans[num[i]]=t[i];
    }
    printf("! %s\n",ans);
    fflush(stdout);
}
/*

i f f x f l b
*/