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
#define MXN 1500
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int b[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int ans=0,now=0;
    set<int> s;
    for(int i = 0;i<n;i++){
        if(b[i]!=a[now]){
            ans++;
       //     printf("%d\n",i);
        }
        else{
            now++;
            while(now!=n&&s.find(a[now])!=s.end()){
                now++;
            }
        }
        s.insert(b[i]);
    }
    printf("%d\n",ans);
}