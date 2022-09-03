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
    int n;
    scanf("%d",&n);
    int cnt[3];
    MEM(cnt);
    char c[300005];
    scanf("%s",c);
    for(int i=0;i<n;i++){
        cnt[c[i]-'0']++;
    }
    for(int i=0;i<n;i++){
        if(cnt[c[i]-'0']>n/3){
            if(cnt[0]<n/3&&0<c[i]-'0'){
                cnt[c[i]-'0']--;
                c[i]='0';
                cnt[0]++;
            }
            else if(cnt[1]<n/3&&1<c[i]-'0'){
                cnt[c[i]-'0']--;
                c[i]='1';
                cnt[1]++;
            }

        }
    }
    for(int i=n-1;i>0;i--){
        if(cnt[c[i]-'0']>n/3){
            cnt[c[i]-'0']--;
            if(cnt[2]<n/3){
                cnt[2]++;
                c[i]='2';
            }
            else if(cnt[1]<n/3){
                cnt[1]++;
                c[i]='1';
            }
            else{
                cnt[0]++;
                c[i]='0';
            }
        }
    }
    printf("%s\n",c);
}