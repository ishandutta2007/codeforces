
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    set<int> s;
    for(int i = 1;i<=n;i++)
        s.insert(i);
    int f[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&f[i]);
        if(f[i]!=0){
            s.erase(f[i]);
        }
    }
    vector<int> v(s.begin(),s.end());
    int now=0;
    for(int i = 1;i<=n;i++){
        if(f[i]==0){
            if(v[now]==i){
                if(now==0)swap(v[now],v[now+1]);
                else swap(v[now],v[now-1]);
            }
            now++;
        }
    }
    now = 0;
    for(int i = 1;i<=n;i++){
        if(f[i]==0){
            printf("%d ",v[now++]);
        }
        else{
            printf("%d ",f[i]);
        }
    }
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/