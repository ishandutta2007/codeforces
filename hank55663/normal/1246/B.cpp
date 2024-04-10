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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i = 2;;i++){
        LL sum=1;
        for(int j=0;j<k;j++){
            sum*=i;
            if(sum>1e6)break;
        }
        if(sum<1e6)v.pb(sum);
        else{
            break;
        }
    }
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        for(auto it:v){
            while(a[i]%it==0)a[i]/=it;
        }
    }
    map<int,int> m;
    LL ans=0;
    for(int i = 0;i<n;i++){
        LL need=1;
        LL tmp=a[i];
        for(int j=2;j*j<=tmp;j++){
            if(tmp%j==0){
                int cnt=0;
                while(tmp%j==0){
                    tmp/=j;
                    cnt++;
                }
                for(int a=cnt;a<k;a++){
                    need=need*j;
                    need=min(need,1000000ll);
                }
            }
        }
        if(tmp!=1){
            int cnt=1;
            for(int a=cnt;a<k;a++){
                need=need*tmp;
                need=min(need,1000000ll);
            }
        }
        if(need<=1e5){
            ans+=m[need];
        }
        m[a[i]]++;
    }
    printf("%lld\n",ans);

}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/